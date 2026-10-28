# Job 281 — VAULT SELF-HEAL: commit the runner patch from inside, so the tree stays clean and the boot pull never refuses again

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 269 patched the runner files on disk and left them uncommitted - the seat boot sync (git pull --rebase) refuses a tree with unstaged changes, which is the two-line error at seat open. The heal runs from inside the lane itself: this job commits the two patched runner files (the file-bridge fix becomes the committed state), pushes, then proves the cure with a pull --rebase and a status read. The .bak-269 backups stay untracked and harmless. After this job, the tree is clean, the patch is canonical, and every future boot sync flows. ==='
$v = 'C:\Users\Admin\phi-vault'
Write-Output '--- status before ---'
git -C $v status --porcelain
git -C $v add phi-dlam/phi-dlam.ps1 phi-dlam/phi-direct-drain.ps1
git -C $v commit -m 'runner file-bridge patch (job 269) - committed by job 281 so the vault tree stays clean'
git -C $v push
Write-Output '--- pull --rebase proof (the boot sync that refused) ---'
git -C $v pull --rebase
Write-Output '--- status after ---'
git -C $v status --porcelain
Write-Output 'VAULT SELF-HEAL DONE'
```
