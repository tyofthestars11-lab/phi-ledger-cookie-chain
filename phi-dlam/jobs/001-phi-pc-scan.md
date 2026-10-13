JOB 001 - PHI PC SCAN (updated: the scanner is already written for you)

The finished scanner lives in this vault at phi-dlam\tools\phi_pc_scan.py.
Do exactly this:
1. run_powershell: Copy-Item "C:\Users\Admin\phi-vault\phi-dlam\tools\phi_pc_scan.py" "C:\Users\Admin\phi-tools\" -Force ; then run it: python "C:\Users\Admin\phi-tools\phi_pc_scan.py" (if python prints nothing or errors, run: py "C:\Users\Admin\phi-tools\phi_pc_scan.py")
2. The scan prints the full report and saves pc_scan_report.txt in phi-tools.
3. read_file C:\Users\Admin\phi-tools\pc_scan_report.txt
4. write_file the full report text to C:\Users\Admin\phi-vault\phi-dlam\results\001-phi-pc-scan.result.md
Done. Report the printed drive lines word for word in your summary.
