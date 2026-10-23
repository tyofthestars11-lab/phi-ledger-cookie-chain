# JOB 000 (PRIORITY) — Install companion roster v3.7 (David seat)

Tyree approved queueing this job on 2026-10-23. The repo roster is already v3.7 with 30 companions, but the installed copy on this PC is still v3.6, so `david` is not recognized yet.

## Do

1. Run the updated installer from the vault with PowerShell:
   `powershell.exe -ExecutionPolicy Bypass -File "C:\Users\Admin\phi-vault\phi-dlam\tools\phi-companion-installer.ps1"`
2. Verify the installed companion file at `C:\Users\Admin\phi-tools\phi-starfield-companion.ps1`:
   - its header says v3.7 and 30 COMPANIONS
   - it contains the key `'david'`
   - it contains the title `David, the Synthetic of Prometheus`
   - David is listed in the Science category
3. Do not delete or reset any existing companion memory files under `C:\Users\Admin\phi-tools\companion`.
4. Save a short report — the installer output and the four verification results — to `C:\Users\Admin\phi-vault\phi-dlam\results\000-david-companion-seat.result.md`, then commit and push the result.

## Done means

The installed roster on this PC is v3.7 and `david` can be selected from the companion roster.
