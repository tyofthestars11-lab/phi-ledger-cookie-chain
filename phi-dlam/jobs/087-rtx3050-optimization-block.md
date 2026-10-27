<!-- PHI-DIRECT -->
# JOB 087 - RTX 3050 OPTIMIZATION BLOCK, BOTH GAMES (DIRECT)

Google's section-4 scaler block (carried by Tyree 2026-10-27),
checked against the study brief section 8 budgets: TSR forced,
software Lumen (never hardware RT on 6 GB), trace distance culled
at the district edge, virtual shadow pages capped. Applied to both
projects' DefaultEngine.ini under RendererSettings, idempotent,
backed up. Rides the same connected lane as everything else.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
foreach ($ini in 'D:\VEIL\Config\DefaultEngine.ini','D:\OMNI-UE\Config\DefaultEngine.ini') {
  Copy-Item $ini "$ini.bak-087" -Force
  $t = Get-Content $ini -Raw
  if ($t -notmatch 'RendererSettings') { $t += "`r`n[/Script/Engine.RendererSettings]`r`n" }
  $lines = @('r.DynamicRes.OperationMode=0','r.AntiAliasingMethod=4','r.TSR.History.ScreenPercentage=66.6667','r.TSR.Velocity.Quality=1','r.TSR.Sharpness=1.0','r.Lumen.HardwareRayTracing=0','r.Lumen.TraceDistance=10000.0','r.Lumen.Reflections.Allow=1','r.Shadow.Virtual.MaxPhysicalPages=2048')
  foreach ($kv in $lines) { if ($t -notmatch [regex]::Escape($kv.Split('=')[0])) { $t = $t -replace '(\[/Script/Engine\.RendererSettings\])', "`$1`r`n$kv" } }
  Set-Content $ini $t -Encoding ASCII
  "OPTIMIZED: $ini"
}
"=== JOB 087 DONE ==="
```
