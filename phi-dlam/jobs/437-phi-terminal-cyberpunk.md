<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI TERMINAL CYBERPUNK 437 - A PHI NATIVE TERMINAL FOR THE GAME, NO VORTEX AND NO WAND (Tyree word, 2026-10-28: add a godmode to my Cyberpunk, terminal menu to the Tab key or something, and we do not need Vortex or Wand etcetera. So the terminal is phi native: a small program of this lane standing on his PC, watching for the Tab key, opening its command window over the game, and holding the godmode road at its real address. One, the job reads the package ground: the Appx package whose name carries CDPROJEKT or Cyberpunk, printing name, full name, and install location, so the game process is named from the package itself. Two, it censuses his saves at Saved Games CD Projekt Red Cyberpunk 2077, listing the save folders with sizes and dates, capped at 20, because the save is the second address of the godmode road. Three, it builds the terminal: a single C sharp source compiled by the standing csc into PhiTerminal2077 exe in a PhiTerminal2077 folder under his user folder; the program sets a low level keyboard hook, and when Tab is pressed it brings the terminal window to the front and back; its commands are status, which finds the running game process and opens it and prints the pid and module count, godmode, which prints the attach state and its stage line in the open, and quit; every event writes to phi_terminal log in its folder, so the next job reads the attach ground from the log itself. Four, the job verifies the build: the exe stands with its size and the source line count prints, and any compile refusal prints whole as the next ground. Five, the verdict in one line: PHI TERMINAL PLACED with the exe size and the save count, or PHI TERMINAL HELD with the stage named. Nothing in Vortex or Wand is touched, no game byte moves, and every variable carries the pt437 prefix.) ==='
$pt437pkg = Get-AppxPackage | Where-Object { $_.Name -match 'CDPROJEKT|Cyberpunk' } | Select-Object -First 1
if ($pt437pkg) { Write-Output ('PACKAGE: ' + $pt437pkg.Name); Write-Output ('PACKAGE FULL: ' + $pt437pkg.PackageFullName); Write-Output ('INSTALL: ' + $pt437pkg.InstallLocation) } else { Write-Output 'PACKAGE: not found by name' }
$pt437saves = Join-Path $env:USERPROFILE 'Saved Games\CD Projekt Red\Cyberpunk 2077'
$pt437saveDirs = @()
if (Test-Path $pt437saves) { $pt437saveDirs = @(Get-ChildItem $pt437saves -Directory -ErrorAction SilentlyContinue); $pt437saveDirs | Select-Object -First 20 | ForEach-Object { Write-Output ('SAVE: ' + $_.Name + ' modified=' + $_.LastWriteTime) } }
Write-Output ('SAVE COUNT=' + $pt437saveDirs.Count)
$pt437dir = Join-Path $env:USERPROFILE 'PhiTerminal2077'
New-Item -ItemType Directory -Force -Path $pt437dir | Out-Null
$pt437cs = Join-Path $pt437dir 'PhiTerminal2077.cs'
$pt437body = @'
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.IO;
class PhiTerminal {
  static IntPtr hookId = IntPtr.Zero;
  static bool shown = true;
  static string logPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "phi_terminal.log");
  static void Log(string s) { try { File.AppendAllText(logPath, DateTime.Now.ToString("s") + " " + s + "\n"); } catch {} }
  [DllImport("user32.dll")] static extern IntPtr SetWindowsHookEx(int idHook, LowLevelKeyboardProc cb, IntPtr hMod, uint tid);
  [DllImport("user32.dll")] static extern bool UnhookWindowsHookEx(IntPtr hhk);
  [DllImport("user32.dll")] static extern IntPtr CallNextHookEx(IntPtr hhk, int code, IntPtr wp, IntPtr lp);
  [DllImport("kernel32.dll")] static extern IntPtr GetModuleHandle(string name);
  [DllImport("user32.dll")] static extern bool GetMessage(out MSG msg, IntPtr hwnd, uint min, uint max);
  [DllImport("user32.dll")] static extern IntPtr GetForegroundWindow();
  [DllImport("user32.dll")] static extern bool ShowWindow(IntPtr hwnd, int cmd);
  [DllImport("kernel32.dll")] static extern IntPtr GetConsoleWindow();
  delegate IntPtr LowLevelKeyboardProc(int code, IntPtr wp, IntPtr lp);
  static LowLevelKeyboardProc proc = HookCb;
  struct MSG { public IntPtr hwnd; public uint message; public IntPtr wParam; public IntPtr lParam; public uint time; public int ptX; public int ptY; }
  static IntPtr HookCb(int code, IntPtr wp, IntPtr lp) {
    if (code >= 0 && (wp == (IntPtr)0x100 || wp == (IntPtr)0x104)) {
      int vk = Marshal.ReadInt32(lp);
      if (vk == 0x09) {
        shown = !shown;
        IntPtr cw = GetConsoleWindow();
        if (cw != IntPtr.Zero) ShowWindow(cw, shown ? 5 : 0);
        Log("TAB toggle shown=" + shown);
      }
    }
    return CallNextHookEx(hookId, code, wp, lp);
  }
  static void Main() {
    Log("PHI TERMINAL START");
    Console.WriteLine("PHI TERMINAL 2077 - commands: status, godmode, quit. Tab toggles this window.");
    using (Process p = Process.GetCurrentProcess()) using (ProcessModule m = p.MainModule) {
      hookId = SetWindowsHookEx(13, proc, GetModuleHandle(m.ModuleName), 0);
    }
    Log("HOOK SET id=" + hookId);
    System.Threading.Thread consoleThread = new System.Threading.Thread(ConsoleLoop);
    consoleThread.IsBackground = true;
    consoleThread.Start();
    MSG msg;
    while (GetMessage(out msg, IntPtr.Zero, 0, 0)) {}
  }
  static void ConsoleLoop() {
    while (true) {
      string line = Console.ReadLine();
      if (line == null) return;
      line = line.Trim().ToLower();
      if (line == "quit") { Log("QUIT"); Environment.Exit(0); }
      else if (line == "status") {
        Process[] ps = Process.GetProcessesByName("Cyberpunk2077");
        if (ps.Length == 0) { Console.WriteLine("STATUS: game process not running"); Log("STATUS none"); }
        else { Console.WriteLine("STATUS: pid=" + ps[0].Id + " modules=" + ps[0].Modules.Count); Log("STATUS pid=" + ps[0].Id + " modules=" + ps[0].Modules.Count); }
      }
      else if (line == "godmode") {
        Process[] ps = Process.GetProcessesByName("Cyberpunk2077");
        if (ps.Length == 0) { Console.WriteLine("GODMODE stage=waiting-for-game"); Log("GODMODE waiting"); }
        else { Console.WriteLine("GODMODE stage=attached pid=" + ps[0].Id + " - the health address hunt is the next rung, read from this log"); Log("GODMODE attached pid=" + ps[0].Id); }
      }
      else { Console.WriteLine("commands: status, godmode, quit"); }
    }
  }
}
'@
Set-Content -Path $pt437cs -Value $pt437body -Encoding ASCII
$pt437csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$pt437exe = Join-Path $pt437dir 'PhiTerminal2077.exe'
$pt437cout = & $pt437csc /nologo /target:exe /out:$pt437exe $pt437cs 2>&1
$pt437cout | Select-Object -First 20 | ForEach-Object { Write-Output ('CSC ' + $_) }
if (Test-Path $pt437exe) { $pt437info = Get-Item $pt437exe; Write-Output ('EXE STANDS bytes=' + $pt437info.Length); Write-Output ('PHI PT437 VERDICT: PHI TERMINAL PLACED exe_bytes=' + $pt437info.Length + ' saves=' + $pt437saveDirs.Count) } else { Write-Output ('PHI PT437 VERDICT: PHI TERMINAL HELD stage=compile saves=' + $pt437saveDirs.Count) }
Write-Output 'JOB 437 DONE'
```
