<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX CHECK READ 428 - WHAT THE VORTEX CYBERPUNK EXTENSION ON THIS PC ACTUALLY DEMANDS AT DISCOVERY, READ FROM THE EXTENSION CODE ITSELF (Ground from job 426, read whole: the phi intent stands written at the game Content folder and at the game base folder, INTENT STANDS 1 at 807 bytes, and the permissions road stopped at the identity wall - the runner identity ADMIN STATE printed False, the launcher owner printed BUILTIN Administrators, icacls answered Access denied with ACL CHANGED 0, and the read proof copy of cpLauncher.exe stayed denied. The launcher SDDL carries a conditional rule granting Users read and execute only inside the game package identity, named in the SDDL by its CDPROJEKTSA app id, so a plain process outside that package reads nothing. Before any further road is authored, the demand itself gets read at its own address: the Vortex extension code for Cyberpunk 2077 standing on this PC. One, the job locates the extension: it searches the standing Vortex install roots, Program Files Black Tree Gaming Ltd, Program Files x86 Black Tree Gaming Ltd, the per user Programs folder, and the AppData Roaming Vortex plugins folder, for files and folders whose name carries cyberpunk, and prints every hit with its full path. Two, in every javascript file the search finds, the job counts and prints the lines that carry Cyberpunk2077.exe, with three lines of context before and ten after on the first matches, so the discovery demand prints in the extension own words. Three, the same files are searched for the store variant tokens xbox, microsoft, gog, steam, and epic, each token with its match count per file, so a standing Xbox variant, if the extension carries one, prints as counted evidence and its absence prints as zero counts. Four, the verdict in one line: VORTEX CHECK READ with the extension file count, the exe mention count, and the xbox mention count. This job is read only: nothing is written, moved, granted, or launched, and every variable carries the vtx428 prefix under the standing ban on automatic variable names.) ==='
$vtx428Roots = @('C:\Program Files\Black Tree Gaming Ltd', 'C:\Program Files (x86)\Black Tree Gaming Ltd', (Join-Path $env:LOCALAPPDATA 'Programs'), (Join-Path $env:APPDATA 'Vortex'))
$vtx428Hits = @()
foreach ($vtx428Root in $vtx428Roots) {
  Write-Output ("ROOT CHECK: " + $vtx428Root + " exists=" + (Test-Path $vtx428Root))
  if (Test-Path $vtx428Root) {
    $vtx428Found = @(Get-ChildItem $vtx428Root -Recurse -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*cyberpunk*' })
    foreach ($vtx428Hit in $vtx428Found) { Write-Output ("CYBERPUNK PATH: " + $vtx428Hit.FullName); $vtx428Hits += $vtx428Hit }
  }
}
Write-Output ("CYBERPUNK PATH COUNT=" + $vtx428Hits.Count)
$vtx428JsFiles = @()
foreach ($vtx428Hit in $vtx428Hits) {
  if ($vtx428Hit.PSIsContainer) { $vtx428JsFiles += @(Get-ChildItem $vtx428Hit.FullName -Recurse -File -Include *.js -ErrorAction SilentlyContinue) } elseif ($vtx428Hit.Extension -eq '.js') { $vtx428JsFiles += $vtx428Hit }
}
$vtx428JsFiles = @($vtx428JsFiles | Sort-Object FullName -Unique)
Write-Output ("EXTENSION JS FILE COUNT=" + $vtx428JsFiles.Count)
$vtx428ExeMentions = 0
$vtx428XboxMentions = 0
Write-Output '--- EXE DEMAND LINES WITH CONTEXT ---'
foreach ($vtx428Js in $vtx428JsFiles) {
  $vtx428ExeLines = @(Select-String -Path $vtx428Js.FullName -Pattern 'Cyberpunk2077.exe' -SimpleMatch -ErrorAction SilentlyContinue)
  $vtx428ExeMentions += $vtx428ExeLines.Count
  Write-Output ("FILE: " + $vtx428Js.FullName + " exe_mentions=" + $vtx428ExeLines.Count)
  $vtx428Shown = 0
  foreach ($vtx428Match in $vtx428ExeLines) {
    if ($vtx428Shown -lt 3) {
      $vtx428Ctx = @(Get-Content $vtx428Js.FullName -ErrorAction SilentlyContinue)
      $vtx428Start = [Math]::Max(0, $vtx428Match.LineNumber - 4)
      $vtx428End = [Math]::Min($vtx428Ctx.Count - 1, $vtx428Match.LineNumber + 9)
      for ($vtx428I = $vtx428Start; $vtx428I -le $vtx428End; $vtx428I++) { Write-Output ("CTX " + ($vtx428I + 1) + ": " + $vtx428Ctx[$vtx428I]) }
      Write-Output 'CTX END'
      $vtx428Shown += 1
    }
  }
}
Write-Output '--- STORE VARIANT TOKEN COUNTS ---'
$vtx428Tokens = @('xbox', 'microsoft', 'gog', 'steam', 'epic')
foreach ($vtx428Js in $vtx428JsFiles) {
  foreach ($vtx428Token in $vtx428Tokens) {
    $vtx428TokenLines = @(Select-String -Path $vtx428Js.FullName -Pattern $vtx428Token -SimpleMatch -ErrorAction SilentlyContinue)
    Write-Output ("TOKEN " + $vtx428Token + " IN " + $vtx428Js.Name + " COUNT=" + $vtx428TokenLines.Count)
    if ($vtx428Token -eq 'xbox') { $vtx428XboxMentions += $vtx428TokenLines.Count }
  }
}
Write-Output '--- VERDICT ---'
Write-Output ("PHI VORTEX428 VERDICT: VORTEX CHECK READ js_files=" + $vtx428JsFiles.Count + " exe_mentions=" + $vtx428ExeMentions + " xbox_mentions=" + $vtx428XboxMentions)
Write-Output 'JOB 428 DONE'
```
