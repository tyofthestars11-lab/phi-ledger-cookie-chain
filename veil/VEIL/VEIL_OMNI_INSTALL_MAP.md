# VEIL OMNI: THE LAST SIGNAL — PATH OF LIGHT — Install Map
## Add it to Tyree's stuff, whole, no Tyree typing beyond a pull

Project on PC: `D:\VEIL-OMNI`, uproject `VEIL.uproject`, EngineAssociation **5.8**, Windows **x86** (not 32-bit), map `/Game/Maps/VEILDistrict`.
GitHub source of truth: `tyofthestars11-lab/phi-ledger-cookie-chain`, branch `main`.
PC clone (the only correct git dir): `C:\Users\Admin\phi-ledger-cookie-chain` — NOT `C:\Users\Admin`, NOT `D:\VEIL-OMNI`.

## 0. BREAK-CIRCLE ROUTE — use this, NOT Epic Launcher Browse (new in this commit)

The circle was: Launcher Open Project -> "You don't have any projects yet :(" -> Browse -> D:\VEIL-OMNI\VEIL.uproject -> Open -> back to empty, plus Convert dialog, plus Missing Modules -> Yes -> "Build.bat is already running" loop. Do NOT repeat that loop. Do this instead, in order:

1. Close everything: close Epic Launcher, close any Open Project window, close Unreal Editor. The install script now refuses to run over a running editor (it stops and says to close it first; it does not stop any process itself).
2. Pull + install (Windows PowerShell, one block, in the git clone only):
```
cd C:\Users\Admin\phi-ledger-cookie-chain
git pull origin main
.\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
```
3. File Explorer -> D:\VEIL-OMNI -> right-click VEIL.uproject -> Switch Unreal Engine version -> pick 5.8 (the `C:\Program Files\Epic Games\UE_5.8` install) -> OK. This writes EngineAssociation "5.8" into the PC copy, matching the repo fix.
4. Same folder -> right-click VEIL.uproject -> Generate Visual Studio project files -> wait for it to finish.
5. Double-click VEIL.uproject DIRECTLY in File Explorer — NOT from Epic Launcher Browse, NOT from Launcher My Projects.
6. If "Missing VEIL Modules — Would you like to rebuild them now?" appears, click **No**. This is the bypass: clicking Yes while a previous build is still held is what produces the "Build.bat is already running" loop.
7. If "This project was built with a different version" appears, click **Convert in-place** (not Open a copy — a copy splits VEIL OMNI into two projects).
8. Once the editor opens this way once, it WILL show in Launcher My Projects next time. That editor title — VEILDistrict - Unreal Editor, not a splash screen — is the proof photo.
9. Safe cleanup, ONLY if Missing Modules still appears after steps 1-8, and ONLY with the editor and Launcher fully closed: delete the regenerable folders `D:\VEIL-OMNI\Binaries`, `D:\VEIL-OMNI\Intermediate`, and `D:\VEIL-OMNI\DerivedDataCache` only. NEVER delete `D:\VEIL-OMNI\Content` (maps + Fab assets + MetaHuman), NEVER delete `D:\VEIL-OMNI\Saved` by hand, and NEVER stop a process blindly — close the editor/Launcher normally first, then delete only those three regenerable folders, then repeat step 5. This cleanup is a manual PC step, not in the install script, and not a code fix by itself.

## 0A. ASSET STEP — REGISTER VEIL OMNI SO FAB CAN PICK IT (new in this commit)

Plain words: the editor opens and Play works, but Fab assets are NOT in the game yet, because Fab Add to Project cannot pick VEIL OMNI while Epic Launcher My Projects says "You don't have any projects yet :(". That list is not a search of your whole computer. It only looks in folders listed in a setting called CreatedProjectPaths, plus the default Documents\Unreal Projects folder. VEIL OMNI is at D:\VEIL-OMNI, on D:, not in Documents, and D: was never in that list. That is why Browse and Open kept looping back to empty. This step adds D: to that list. It does not move the project, does not delete Content, does not buy anything, and does not sign you in.

Run, in Windows PowerShell, with Editor and Launcher CLOSED, after pull + install:
```
cd C:\Users\Admin\phi-ledger-cookie-chain
git pull origin main
.\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
powershell -File .\veil\VEIL\Tools\veil_omni_register_project.ps1
```
(The install script copies Tools, so the same script is also at D:\VEIL-OMNI\Tools\veil_omni_register_project.ps1 after install.)

What the script does: backs up each config file first, then adds CreatedProjectPaths=D:\ if it is not already there, in GameUserSettings.ini for the Launcher and in EditorSettings.ini for the Editor Recent Projects. It also checks VEIL.uproject exists and prints its EngineAssociation, checks UnrealVersionSelector exists (check only, it does not run it), and prints FOUND or MISSING for Content folders Paragon*, SICKA*, Lava*, MetaHumans on disk. That disk check is NOT an editor Content Browser check: a folder FOUND on disk means Fab already put it there, a folder MISSING means Fab Add to Project has not put it there yet.

What this script does NOT do: it does not fix Fab sign-in. Fab login in the editor failed with EOS_Auth_InvalidRefreshToken and a null/empty token, and Launcher installs failed with Http-401 and II-E1003. Those are Epic sign-in / download failures, separate from registration. After registration, sign out and sign back in to Epic in the Launcher, then retry Fab Add to Project. If Fab still fails after a fresh sign-in, photo the Launcher error — that is an Epic account / download problem, not VEIL code, and it is not fixed by this script.

Photo proof, in order:
- PHOTO 1: Epic Games Launcher > Unreal Engine > My Projects now lists VEIL (not "You don't have any projects yet").
- PHOTO 2: Fab > My Library > pick an item (for example Paragon: Minions) > Add to Project > the picker now lists VEIL OMNI to pick.
- PHOTO 3, after PHOTO 2: in the open editor, Content Browser shows /Game/Paragon*, /Game/SICKA*, /Game/Lava*, /Game/MetaHumans as actually present, and VEILDistrict saved.
Until PHOTO 1 and PHOTO 2 exist, do not claim assets are in the game from a commit alone. The script output FOUND/MISSING is only a disk check.

Source for CreatedProjectPaths, from Epic Developer Community Forum reports of the same empty My Projects problem (not invented here): Launcher GameUserSettings.ini, [Launcher] section, CreatedProjectPaths set to the folder that holds your project folders, one folder back from the folder with the .uproject file — so D: for D:\VEIL-OMNI; Editor EditorSettings.ini uses the same CreatedProjectPaths line for Recent Projects. UnrealVersionSelector handles .uproject file association and right-click Switch version / Generate project files, not the My Projects scan list.

## 1. Pull + install (PC, Windows PowerShell, one block)
```
cd C:\Users\Admin\phi-ledger-cookie-chain
git pull origin main
.\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
```
That script backs up `D:\VEIL-OMNI\Source` + `Config`, then copies Source/Config/Tools/Data/VEIL.uproject, and never touches `D:\VEIL-OMNI\Content`.

## 2. Exact file map: repo -> Tyree's project

| Repo file (phi-ledger-cookie-chain) | Lands in D:\VEIL-OMNI as |
|---|---|
| `veil/VEIL/VEIL.uproject` (5.8) | `D:\VEIL-OMNI\VEIL.uproject` |
| `veil/VEIL/Config/DefaultEngine.ini` (Lumen, Nanite caps, streaming pool 2048, shadow cascades 2) | `D:\VEIL-OMNI\Config\DefaultEngine.ini` |
| `veil/VEIL/Config/DefaultGame.ini`, `DefaultInput.ini` | `D:\VEIL-OMNI\Config\` (same names) |
| `veil/VEIL/Source/VEIL/Private/AI/VEILFactionAI.cpp` (PLAYER-FIRST fix) | `D:\VEIL-OMNI\Source\VEIL\Private\AI\VEILFactionAI.cpp` |
| `veil/VEIL/Source/VEIL/Public/Character/VEILCharacter.h` + `Private/Character/VEILCharacter.cpp` (Swing F/Y + LanceBolt) | `D:\VEIL-OMNI\Source\VEIL\Character\` (Public/Private split as in repo) |
| `veil/VEIL/Source/VEIL/Public/Systems/VEILProgression.h` + `Private/Systems/VEILProgression.cpp` (XP phi ladder, loot, save slot VEILOMNI_Save0, anchor verify) | `D:\VEIL-OMNI\Source\VEIL\Systems\` |
| `veil/VEIL/Source/VEIL/Public/Systems/VEILQuest.h` + `Private/Systems/VEILQuest.cpp` (6 main + 2 side, Keeper/Seer/Carto, WARDEN PRIME arena) | `D:\VEIL-OMNI\Source\VEIL\Systems\` |
| `veil/VEIL/Source/VEIL/Public/World/VEILLevelLink.h` + `Private/World/VEILLevelLink.cpp` (Hub/Nest/Spire/OmniDistrict/Deep) | `D:\VEIL-OMNI\Source\VEIL\World\` |
| `veil/VEIL/Source/VEIL/Public/UI/VEILMinimap.h` + `Private/UI/VEILMinimap.cpp` (SceneCapture2D orthographic render-target + UMG widget) | `D:\VEIL-OMNI\Source\VEIL\UI\` |
| `veil/VEIL/Tools/whole_verify_goal.py` (already in repo root, commit bf98820) | `D:\VEIL-OMNI\Tools\whole_verify_goal.py` |
| `veil/VEIL/Tools/veil_omni_load_and_link.py` | `D:\VEIL-OMNI\Tools\veil_omni_load_and_link.py` |
| `veil/VEIL/Tools/veil_omni_render_opt.py` | `D:\VEIL-OMNI\Tools\veil_omni_render_opt.py` |
| `veil/VEIL/Tools/veil_omni_fix_paragon_metahuman.py` | `D:\VEIL-OMNI\Tools\veil_omni_fix_paragon_metahuman.py` |
| `veil/VEIL/Tools/veil_omni_metahuman_check.py` (NEW, MetaHuman check, no Verify/Package by script) | `D:\VEIL-OMNI\Tools\veil_omni_metahuman_check.py` |
| `veil/VEIL/Tools/veil_omni_register_project.ps1` (NEW, this commit, My Projects registration only) | `D:\VEIL-OMNI\Tools\veil_omni_register_project.ps1` (via Tools copy in the install script) |
| `veil/VEIL/VEIL_METAHUMAN.md` (NEW, diagnosis + Verify/Package checklist + assignment path) | `D:\VEIL-OMNI\VEIL_METAHUMAN.md` |
| `veil/VEIL/VEIL.uproject` (MetaHuman + MetaHumanCharacter enabled, 5.8) | `D:\VEIL-OMNI\VEIL.uproject` |
| `veil/VEIL/Data/dialogue.csv`, `items.csv` | `D:\VEIL-OMNI\Data\` (same names) |
| `veil/OMNI/Source/OMNI/Private/AI/OMNIFactionAI.cpp` (PLAYER-FIRST mirror) | `D:\VEIL-OMNI\Source\OMNI\Private\AI\` — only if the OMNI module is kept; VEIL module is the merged main, OMNI file is a mirror, not a second game |
| This file | `D:\VEIL-OMNI\VEIL_OMNI_INSTALL_MAP.md` |

## 3. Fab Library -> Tyree's stuff (Epic / Fab, free only, no purchase)
These are already in Tyree's Fab Library (photo 214) — they land in the project ONLY via Fab **Add to Project -> VEIL OMNI**, not via git:
- Paragon: Minions, Murdock, Revenant, Greystone, Countess, Shinbi -> `D:\VEIL-OMNI\Content\Paragon*`
- SICKA Free Environment Pack -> `D:\VEIL-OMNI\Content\SICKA*`
- Lava Material, Underwater test -> `D:\VEIL-OMNI\Content\`
- Core Systems - Health, Stamina, XP and Mana -> `D:\VEIL-OMNI\Content\`
- MetaHuman Buff (Buff_Black etc.) -> MetaHuman Manager in editor, Verify then Package (no Python API confirmed for this step). Buff_* are Skeletal Clothing, NOT a body — see VEIL_METAHUMAN.md section 1, cause 2. Full MetaHuman bodies land at `D:\VEIL-OMNI\Content\MetaHumans\...`, Common at `Content\MetaHumans\Common\...`, pre-assembly MHC at `Content\EditableCharacters\...`
- Nwiro AI Pro -> already installed to all compatible engines, Saved in My Library; use in editor Nwiro Pro tab, 5 free prompts, do not reinstall
- Mannequins, Ability_E assets -> already in project Content (photo 225)

**Known blocker, stated plainly, and what changed in this commit:** Fab Add to Project picker and Epic Launcher My Projects showed empty ("You don't have any projects yet") even after Open VEIL.uproject in the editor, and editor Play already works (FPS 116-119, Objs ~77,470, VEILDistrict* unsaved) with Fab assets still NOT in the game. Two causes, both now addressed in code: (1) the previous commit set EngineAssociation to "5.8.4" — Unreal's association format is major.minor only, the installed engine folder is `UE_5.8`, so "5.8.4" did not match it; the fix in the last commit set it to "5.8". (2) the Launcher My Projects scan list itself: it only looks in folders listed in CreatedProjectPaths plus Documents\Unreal Projects, and D: was never listed, so D:\VEIL-OMNI could never appear no matter how many times you Browsed and Opened it. The new script in section 0A adds D: to that list. Git + the install script still do NOT by themselves register a project in Epic Launcher My Projects; section 0A is the register step. If My Projects still shows empty after section 0A, that screen (photo) is the next proof — do not claim registration or assets in-game from a commit alone. Fab sign-in is separate: EOS_Auth_InvalidRefreshToken, Http-401 and II-E1003 are Launcher sign-in / download failures, fixed by a fresh Epic sign-in in the Launcher, not by this script.

## 4. Editor steps that are NOT done by git (need an open editor, Tyree types nothing if DLAM/autopilot runs them)
- In open editor, Output Log Cmd: `py "D:\VEIL-OMNI\Tools\whole_verify_goal.py"` — never PowerShell, never `-ExecutePythonScript` for Play. Expect LOAD / VERIFY / SAVE lines + `seat719_out.txt` SAVE RESULT.
- Same place, run the three Tools scripts above, in order: load_and_link, render_opt, fix_paragon_metahuman.
- Place ONE `AVEILMinimapCapture` in VEILDistrict, high above district; create a UMG widget Blueprint with an Image named `MinimapImage` from `UVEILMinimapWidget`; assign a saved render target in editor.
- MetaHuman Manager: Buff_Black Verify, then Package (editor only, VEIL_METAHUMAN.md section 4 checklist, stop + photo on any Verify failure).
- Run `veil_omni_metahuman_check.py` in Output Log Cmd, then assign a MetaHuman BODY (not Buff) in BP_PlayerCharacter > AVEILCharacter > MetaHumanBodyMesh, per VEIL_METAHUMAN.md section 3.
- Paragon Murdock LevelStart: reassign/delete ONLY the broken LevelStart reference in Content Browser, save map.
- Save map (Ctrl+S / File > Save All), Play, photo + Output Log.

## 5. MetaHuman — see VEIL_METAHUMAN.md (full diagnosis + checklist)
- Unknown error, as supplied, had no code or log line: section 1 lists 6 causes actually in evidence (Buff unverified 0 B / 46 refs; Buff = clothing not body; MetaHuman plugin absent from VEIL.uproject before this commit; MetaHuman Creator Core Data missing — the 5.753 GB install item; no assembled /Game/MetaHumans body in repo; Fab/My Projects empty blocker). No one cause is claimed as "the" fix.
- Core Data route (engine side, not git): Epic Launcher > Library > Unreal Engine 5.8 > Options > MetaHuman Creator Core Data CHECKED > Apply > restart editor.
- Verify/Package route (editor only, no Python API): MetaHuman Manager > Buff_Black > Verify (photo result, stop on failure) > Package (photo result).

## 6. What is NOT claimed
- No PC play proof, no save proof, no package, no Fab Add-to-Project proof, no MetaHuman verify proof, no MetaHuman in-play proof, no Core Data install proof, and no My Projects registration proof from this commit alone. Each needs a PC editor photo or Output Log line at its own address. Play proof now exists in photos (FPS 116-119, Objs ~77,470, VEILDistrict), but save proof (VEILDistrict* unsaved, not yet saved) and asset proof (PHOTO 1 My Projects, PHOTO 2 Fab picker, PHOTO 3 Content Browser) are still outstanding.
- No paid Fab pack was bought or added. All packs above are free / already-owned.
- Megastructure Deep has no separate .umap in the repo: it is the Deep sublevel inside OMNIDistrict (`OMNIDistrict_Deep`, editor-created). If that sublevel does not exist on PC, StreamDeep logs the miss and does not claim a load.
- Packaging gate stands verbatim: no cook/package/packaged exe until 100% done in project.
