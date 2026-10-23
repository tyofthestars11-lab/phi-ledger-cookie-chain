# JOB 007 — Fix working-set trimming pressure (reversible, read-back verified)

Tyree's word (2026-10-23): "Let's fix the trimming working sets." Background: under memory pressure Windows trims background processes' working sets; the pages then fault back in as hitches. This job reduces that pressure with three standard, reversible levers and proves each with a before/after read. It does NOT purge standby memory or any working set (that makes trimming worse), does NOT remove the pagefile, and does NOT touch Memory Compression in this pass (Job 006 reports its state).

## Guard

First read elevation: `([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)`. If False, write "NOT-ELEVATED — no changes made" plus the read to the result path below, commit and push, and stop.

## Do

1. BEFORE read, print and keep: Win32PrioritySeparation (HKLM:\SYSTEM\CurrentControlSet\Control\PriorityControl), AutomaticManagedPagefile (Win32_ComputerSystem), SysMain Status + StartType, free RAM GB.
2. Apply exactly these three changes:
   - Foreground scheduling boost: Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\PriorityControl' -Name Win32PrioritySeparation -Value 38 -Type DWord. (Standard foreground-favored scheduling: the app in front keeps its working set and quantum priority.)
   - Pagefile to system-managed: if AutomaticManagedPagefile is False, set it True via Set-CimInstance on Win32_ComputerSystem. (A missing or undersized pagefile forces hard trimming under commit pressure; system-managed removes that ceiling. Applies fully at reboot — say so in the report.)
   - SysMain stand-down: Stop-Service SysMain -Force, then Set-Service SysMain -StartupType Disabled. (SysMain prefetch churn is a standing source of working-set pressure. Reversible: Set-Service SysMain -StartupType Automatic and Start-Service restores it.)
3. AFTER read: print the same four values again, plus free RAM GB.
4. Save BEFORE and AFTER blocks to `C:\Users\Admin\phi-vault\phi-dlam\results\007-working-set-fix.result.md`, commit and push.

## Rules

- Only the three changes above. Nothing deleted, no other registry keys, no other services.
- Report values exactly as read back, same labels and units. If any change fails, print the failure plainly in the result instead of retrying silently.
