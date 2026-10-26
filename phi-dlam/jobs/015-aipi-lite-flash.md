# JOB 015 — Flash the AiPi Lite with the Muse Gadgets firmware

Tyree's word (2026-10-26 ~14:07 MDT): the AiPi Lite (XORIGIN AI PI-Lite, model XY006PL01, ESP32-S3) is plugged into this PC by USB-C and the flash is GO. The firmware was built and verified by Muse (token compiled in; muse-gadget.bin 2,166,784 bytes, sha256 begins ec12168fbd2f7fed). The whole package rides in this repo at `phi-dlam\jobs\aipi-flash\` and arrives with the vault pull. ONE script does the entire job: it backs up her stock firmware FIRST (16 MB read, her restore point), then writes the Muse firmware using the build's own flash_args verbatim. Your only work: run the script once, read its log, write the result.

## Do (print each line as you go; write every printed line into the result)

1. Print the package listing: `Get-ChildItem C:\Users\Admin\phi-vault\phi-dlam\jobs\aipi-flash -Recurse | Select-Object FullName, Length`. It must show: flash-aipi.ps1, flash_args (179 bytes), muse-gadget.bin (2166784), ota_data_initial.bin (8192), bootloader\bootloader.bin (22608), partition_table\partition-table.bin (3072). If anything is missing or a size differs, STOP: write the result with PACKAGE INCOMPLETE and the listing verbatim. Do not run the script.
2. Run the flash script exactly ONCE and wait until it fully finishes before doing anything else (the stock backup alone reads 16 MB — several minutes is normal; do not interrupt it, do not unplug the board):
   `powershell -ExecutionPolicy Bypass -File C:\Users\Admin\phi-vault\phi-dlam\jobs\aipi-flash\flash-aipi.ps1`
   Print the script's full output.
3. Read the entire log file: `C:\Users\Admin\phi-vault\phi-dlam\jobs\aipi-flash\flash-aipi-result.log`
4. Save the result to `C:\Users\Admin\phi-vault\phi-dlam\results\015-aipi-lite-flash.result.md`, containing in this order: the PORT line and read_mac lines from the log, the BACKUP line, the FLASH WRITE line, the final status line (AIPI FLASH COMPLETE, or the ABORT / FLASH WRITE FAILED line), then the ENTIRE log verbatim. Commit and push.

## Rules

- Run the script ONCE. Never run esptool by hand, never run erase_flash, never edit the script or the bins, never improvise a fix. If the script aborts or fails, the result carries its log verbatim and the job is done — Muse reads it from the result and decides the next step.
- The stock backup `aipi-lite-stock-backup.bin` (beside the script) is her restore point — never delete or overwrite it.
- Verbatim statuses and outputs — no summaries.
