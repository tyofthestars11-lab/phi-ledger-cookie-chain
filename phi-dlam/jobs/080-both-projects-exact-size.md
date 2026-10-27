<!-- PHI-DIRECT -->
# JOB 080 - BOTH PROJECTS, EXACT SIZE IN GB (DIRECT)

Tyree asked: how much are both, in GBs? Last measured (job 061):
D:\VEIL 2.62 GB, D:\OMNI-UE 0 GB - before builds 12/13 and OMNI
builds 1-5 landed their binaries. This job measures both projects
exactly as they stand now, with the per-folder split, plus the
packages and the drive state. Read-only.

```powershell
foreach ($p in 'D:\VEIL','D:\OMNI-UE','D:\VEIL-Package','D:\OMNI-Package','D:\OMNI-RPG') {
  if (Test-Path $p) {
    $s = (Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
    "{0} = {1:N2} GB" -f $p, ($s/1GB)
    Get-ChildItem $p -Directory -ErrorAction SilentlyContinue | ForEach-Object {
      $ss = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
      if ($ss -gt 10MB) { "  {0} {1:N2} GB" -f $_.Name, ($ss/1GB) }
    }
  } else { "ABSENT: $p" }
}
$d = Get-PSDrive D; "D: FREE {0:N1} GB / TOTAL {1:N1} GB" -f ($d.Free/1GB), (($d.Used+$d.Free)/1GB)
$epic = (Get-ChildItem 'C:\Program Files\Epic Games\UE_5.8' -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
"ENGINE UE_5.8 = {0:N2} GB (on C)" -f ($epic/1GB)
"=== JOB 080 DONE ==="
```
