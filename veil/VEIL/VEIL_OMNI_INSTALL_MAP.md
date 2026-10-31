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

**Known blocker, stated plainly, and what changed in this commit:** Fab Add to Project picker and Epic Launcher My Projects showed empty ("You don't have any projects yet") even after Open VEIL.uproject in the editor. Root cause found in this audit: the previous commit set EngineAssociation to "5.8.4". Unreal's own association format is major.minor only (for example "5.0", not "5.0.3"; a 5.5 project runs on 5.5.1/5.5.2/5.5.3, and the version selector matches on major.minor). The installed engine folder is `UE_5.8`, so "5.8.4" does not match it: every open prompts "built with a different version", Convert runs, and the Launcher scan drops the project back to empty — the circle. This commit sets VEIL.uproject EngineAssociation to "5.8" only. OMNI.uproject was NOT changed in this commit: OMNI is a mirror, not a second game to launch, and VEIL is the merged main module. Git + this install script still do NOT by themselves register a project in Epic Launcher My Projects; the break-circle route in section 0 is the register step. If My Projects still shows empty after section 0, that screen (photo) is the next proof — do not claim registration from a commit alone.

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
- No PC play proof, no save proof, no package, no Fab Add-to-Project proof, no MetaHuman verify proof, no MetaHuman in-play proof, no Core Data install proof, and no My Projects registration proof from this commit alone. Each needs a PC editor photo or Output Log line at its own address.
- No paid Fab pack was bought or added. All packs above are free / already-owned.
- Megastructure Deep has no separate .umap in the repo: it is the Deep sublevel inside OMNIDistrict (`OMNIDistrict_Deep`, editor-created). If that sublevel does not exist on PC, StreamDeep logs the miss and does not claim a load.
- Packaging gate stands verbatim: no cook/package/packaged exe until 100% done in project.
