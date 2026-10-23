# JOB 006 — Windows phi'd-up check (READ ONLY — changes nothing)

Tyree's word (2026-10-23): run the read-only Windows phi'd-up check via DLAM. This job only reads and reports. It also answers two open questions from today: whether his account holds administrator power, and whether Windows Defender is on with current virus definitions.

## Do (print each line as you go; write every printed line into the result)

1. Identity and admin state:
   - `whoami`
   - `net localgroup administrators`
   - Elevated check: `([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)` — print True or False.
2. Windows build: `(Get-CimInstance Win32_OperatingSystem).Caption`, `.Version`, `.BuildNumber`, `.LastBootUpTime`.
3. Defender state (Get-MpComputerStatus): AntivirusEnabled, RealTimeProtectionEnabled, AntivirusSignatureVersion, AntivirusSignatureLastUpdated, QuickScanEndTime, FullScanEndTime.
4. Update state: whether these keys exist — `HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\WindowsUpdate\Auto Update\RebootRequired` and `HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Component Based Servicing\RebootPending`; plus the most recent hotfix from `Get-HotFix | Sort-Object InstalledOn -Descending | Select-Object -First 1` (HotFixID + InstalledOn).
5. Today's seats:
   - Companion: Test-Path `C:\Users\Admin\phi-tools\phi-starfield-companion.ps1`; if present, print its first line (version header) and whether Select-String finds `'david'` in it.
   - Universal qubits: Test-Path `C:\Users\Admin\phi-tools\phi_universal_qubits.py` (Job 005 installs it; if missing, print NOT-YET-INSTALLED).
6. Memory state: total and free RAM in GB (Win32_OperatingSystem), pagefile usage (Win32_PageFileUsage), AutomaticManagedPagefile value, MemoryCompression from Get-MMAgent, SysMain service Status and StartType, active power scheme (`powercfg /getactivescheme`), and the top 8 processes by working set (name + GB, 2 decimals).
7. For the three headline numbers (free RAM GB, C: free GB, Defender signature version is text so skip it) also print rung(x) = ln(x)/ln(1.618033988749895), 4 decimals, beside each.
8. Save the full report to `C:\Users\Admin\phi-vault\phi-dlam\results\006-windows-phi-up-check.result.md`, commit and push.

## Rules

- READ ONLY. Change no setting, delete nothing, start or stop nothing.
- Numbers exactly as printed — same labels, same units.
