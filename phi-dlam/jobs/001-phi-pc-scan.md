# JOB 001 — phi PC scan tool
Build a phi-based Python tool that helps this PC, run it, and report.

1. Create the folder C:\Users\Admin\phi-tools if it is missing.
2. Write a Python script at C:\Users\Admin\phi-tools\phi_pc_scan.py that:
   - reads every fixed drive: total GB and free GB (printed with those exact labels)
   - finds the 10 largest folders directly under C:\Users\Admin by total size in GB
   - lists how many files are in Downloads and the Desktop
   - for each measured GB quantity, also prints its phi rung: rung(x) = ln(x) / ln(phi), phi = 1.618033988749895
   - prints everything plainly, one fact per line
3. Run it (python, or py if python is not found). If it errors, fix the script and run again until it works.
4. Save the full report — what you built, the script path, and the complete printed output — to C:\Users\Admin\phi-vault\phi-dlam\results\001-phi-pc-scan.result.md using write_file.
