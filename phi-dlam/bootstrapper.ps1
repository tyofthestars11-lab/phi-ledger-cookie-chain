# PHI-DLAM BOOTSTRAPPER - permanent. This file never changes again.
# It pulls Tyree's repo (the vault) and runs the living runner from it.
# Updates are published to the repo by Muse; the DLAM updates itself at every launch.
git -C $env:USERPROFILE\phi-vault pull --quiet
& $env:USERPROFILE\phi-vault\phi-dlam\phi-dlam.ps1
