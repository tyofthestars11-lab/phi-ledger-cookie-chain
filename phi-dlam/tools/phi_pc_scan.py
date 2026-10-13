#!/usr/bin/env python3
"""PHI PC SCAN - Tyree's PC, read by the phi lens.
phi = 1.618033988749895 ; rung(x) = ln(x) / ln(phi)
Prints the full report and saves it next to this script."""
import os, math, shutil, time

PHI = 1.618033988749895

def rung(x):
    return math.log(x) / math.log(PHI) if x and x > 0 else float('nan')

def gb(b):
    return b / (1024 ** 3)

def folder_size(path, cap=400000):
    total, count, capped = 0, 0, False
    for root, dirs, files in os.walk(path):
        dirs[:] = [d for d in dirs if not os.path.islink(os.path.join(root, d))]
        for f in files:
            try:
                total += os.path.getsize(os.path.join(root, f))
                count += 1
            except OSError:
                pass
            if count >= cap:
                capped = True
                break
        if capped:
            break
    return total, count, capped

def main():
    lines = []
    def out(s=''):
        print(s)
        lines.append(s)
    home = os.path.expanduser('~')
    out('PHI PC SCAN - ' + time.strftime('%Y-%m-%d %H:%M'))
    out('phi = 1.618033988749895 ; rung(x) = ln(x)/ln(phi)')
    out('')
    out('DRIVES')
    for letter in 'CDEFG':
        p = letter + ':\\'
        if os.path.exists(p):
            t, u, f = shutil.disk_usage(p)
            out(f'{letter}: total {gb(t):.1f} GB (rung {rung(gb(t)):.3f}), used {gb(u):.1f} GB (rung {rung(gb(u)):.3f}), free {gb(f):.1f} GB (rung {rung(gb(f)):.3f})')
    out('')
    out('TOP FOLDERS UNDER ' + home)
    rows = []
    for name in os.listdir(home):
        full = os.path.join(home, name)
        if os.path.isdir(full) and not os.path.islink(full):
            size, count, capped = folder_size(full)
            rows.append((size, name, count, capped))
    rows.sort(reverse=True)
    for size, name, count, capped in rows[:10]:
        tag = ' (capped count)' if capped else ''
        out(f'{name}: {gb(size):.2f} GB (rung {rung(gb(size)):.3f}), {count} files{tag}')
    out('')
    out('COUNTS')
    for name in ('Downloads', 'Desktop', 'Documents', 'Pictures'):
        full = os.path.join(home, name)
        if os.path.isdir(full):
            n = sum(len(files) for _, _, files in os.walk(full))
            out(f'{name}: {n} files (rung {rung(n):.3f})')
    out('')
    out('phi in front. TYREE - primary source.')
    report = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'pc_scan_report.txt')
    with open(report, 'w', encoding='utf-8') as fh:
        fh.write('\n'.join(lines))
    print('Report saved: ' + report)

if __name__ == '__main__':
    main()
