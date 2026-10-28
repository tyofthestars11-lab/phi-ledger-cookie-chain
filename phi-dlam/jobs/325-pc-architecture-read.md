<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PC ARCHITECTURE READ - THE MACHINES OWN LINES (Tyree 2026-10-27 23:58 MDT: I am windows 32 / We are not x64 on this pc / You know the specs. His word stands in his house; this job reads the specs from the machine itself so every seat reasons from the same lines: OS architecture as Windows reports it, process architecture, and the bitness of the actual game binaries the lane has been cooking. READ-ONLY.) ==='
"Is64BitOperatingSystem: $([Environment]::Is64BitOperatingSystem)" | Write-Output
"Is64BitProcess: $([Environment]::Is64BitProcess)" | Write-Output
"PROCESSOR_ARCHITECTURE: $env:PROCESSOR_ARCHITECTURE" | Write-Output
$os = Get-CimInstance Win32_OperatingSystem -ErrorAction SilentlyContinue
if ($os) { "OS caption: $($os.Caption) | OSArchitecture: $($os.OSArchitecture) | BuildNumber: $($os.BuildNumber)" | Write-Output }
$cpu = Get-CimInstance Win32_Processor -ErrorAction SilentlyContinue | Select-Object -First 1
if ($cpu) { "CPU: $($cpu.Name) | Architecture: $($cpu.Architecture) | DataWidth: $($cpu.DataWidth)" | Write-Output }
foreach ($root in @('D:\Builds\VEIL\VEIL_DONE\Windows','D:\Builds\OMNI\OMNI_DONE\Windows')) {
  "--- $root ---" | Write-Output
  Get-ChildItem $root -Recurse -Filter '*.exe' -File -ErrorAction SilentlyContinue | ForEach-Object { "$($_.FullName) | $([math]::Round($_.Length/1MB,2)) MB" } | Write-Output
}
Write-Output 'ARCHITECTURE READ DONE'
```
