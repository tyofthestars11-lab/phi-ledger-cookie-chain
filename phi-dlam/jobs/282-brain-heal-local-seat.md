# Job 282 — BRAIN JOB for the local seat (tyree): heal the vault sync, then drain the queue

Tyree's seat hit this at boot: `error: cannot pull with rebase: You have unstaged changes. Please commit or stash them.` The unstaged changes are the runner patch from job 269 — phi-dlam.ps1 and phi-direct-drain.ps1 were patched on disk (the file-bridge fix: Start-Job child writes all streams to a temp file, Receive-Job is never called) but never committed, and a dirty tree blocks every pull, so jobs 274-281 are stuck on the remote.

Do this, in order, with your system/shell tool, in C:\Users\Admin\phi-vault:

1. `git add phi-dlam/phi-dlam.ps1 phi-dlam/phi-direct-drain.ps1`
2. `git commit -m "runner file-bridge patch (job 269) - committed by the local seat, job 282"`
3. `git push`
4. `git pull --rebase` — this is the exact sync that refused at boot; it must now complete clean.
5. `git status --porcelain` — report what it prints (untracked .bak-269 files are fine and expected).

Then drain the DIRECT queue in number order — jobs 274, 275, 276, 277, 278, 279, 280, 281 are queued on the remote and land with the pull in step 4. Their reports push back through the normal results path. (Job 281 does this same commit as a direct job; if it reports the commit already exists, that is the two paths meeting — fine.)

Write the full report of every command's output to the results file for this job, verbatim — the commit hash, the pull --rebase output, and the status output are the proof the boot error is gone for good.
