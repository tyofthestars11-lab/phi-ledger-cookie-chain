# VEIL OMNI: THE LAST SIGNAL — PATH OF LIGHT — Install Map
## Add it to Tyree's stuff, whole, no Tyree typing beyond a pull

Project on PC: `D:\VEIL-OMNI`, uproject `VEIL.uproject`, EngineAssociation **5.8.4**, Windows **x86** (not 32-bit), map `/Game/Maps/VEILDistrict`.
GitHub source of truth: `tyofthestars11-lab/phi-ledger-cookie-chain`, branch `main`.
PC clone (the only correct git dir): `C:\Users\Admin\phi-ledger-cookie-chain` — NOT `C:\Users\Admin`, NOT `D:\VEIL-OMNI`.

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
| `veil/VEIL/VEIL.uproject` (5.8.4) | `D:\VEIL-OMNI\VEIL.uproject` |
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
| `veil/VEIL/Data/dialogue.csv`, `items.csv` | `D:\VEIL-OMNI\Data\` (same names) |
| `veil/OMNI/Source/OMNI/Private/AI/OMNIFactionAI.cpp` (PLAYER-FIRST mirror) | `D:\VEIL-OMNI\Source\OMNI\Private\AI\` — only if the OMNI module is kept; VEIL module is the merged main, OMNI file is a mirror, not a second game |
| This file | `D:\VEIL-OMNI\VEIL_OMNI_INSTALL_MAP.md` |

## 3. Fab Library -> Tyree's stuff (Epic / Fab, free only, no purchase)
These are already in Tyree's Fab Library (photo 214) — they land in the project ONLY via Fab **Add to Project -> VEIL OMNI**, not via git:
- Paragon: Minions, Murdock, Revenant, Greystone, Countess, Shinbi -> `D:\VEIL-OMNI\Content\Paragon*`
- SICKA Free Environment Pack -> `D:\VEIL-OMNI\Content\SICKA*`
- Lava Material, Underwater test -> `D:\VEIL-OMNI\Content\`
- Core Systems - Health, Stamina, XP and Mana -> `D:\VEIL-OMNI\Content\`
- MetaHuman Buff (Buff_Black etc.) -> MetaHuman Manager in editor, Verify then Package (no Python API confirmed for this step)
- Nwiro AI Pro -> already installed to all compatible engines, Saved in My Library; use in editor Nwiro Pro tab, 5 free prompts, do not reinstall
- Mannequins, Ability_E assets -> already in project Content (photo 225)

**Known blocker, stated plainly:** Fab Add to Project picker and Epic Launcher My Projects showed empty ("You don't have any projects yet") even after Open VEIL.uproject in the editor. Git + this install script do NOT by themselves register a project in Epic Launcher My Projects. After pull + install, open `VEIL.uproject` (5.8.4) from Epic Launcher > Unreal Engine > My Projects; if it still shows empty, that screen (photo) is the next proof Muse needs — do not claim registration from a commit alone.

## 4. Editor steps that are NOT done by git (need an open editor, Tyree types nothing if DLAM/autopilot runs them)
- In open editor, Output Log Cmd: `py "D:\VEIL-OMNI\Tools\whole_verify_goal.py"` — never PowerShell, never `-ExecutePythonScript` for Play. Expect LOAD / VERIFY / SAVE lines + `seat719_out.txt` SAVE RESULT.
- Same place, run the three Tools scripts above, in order: load_and_link, render_opt, fix_paragon_metahuman.
- Place ONE `AVEILMinimapCapture` in VEILDistrict, high above district; create a UMG widget Blueprint with an Image named `MinimapImage` from `UVEILMinimapWidget`; assign a saved render target in editor.
- MetaHuman Manager: Buff_Black Verify, then Package (editor only).
- Paragon Murdock LevelStart: reassign/delete ONLY the broken LevelStart reference in Content Browser, save map.
- Save map (Ctrl+S / File > Save All), Play, photo + Output Log.

## 5. What is NOT claimed
- No PC play proof, no save proof, no package, no Fab Add-to-Project proof, no MetaHuman verify proof, and no My Projects registration proof from this commit alone. Each needs a PC editor photo or Output Log line at its own address.
- No paid Fab pack was bought or added. All packs above are free / already-owned.
- Megastructure Deep has no separate .umap in the repo: it is the Deep sublevel inside OMNIDistrict (`OMNIDistrict_Deep`, editor-created). If that sublevel does not exist on PC, StreamDeep logs the miss and does not claim a load.
- Packaging gate stands verbatim: no cook/package/packaged exe until 100% done in project.
