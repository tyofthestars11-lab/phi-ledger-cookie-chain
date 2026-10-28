<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI EXTENSION FOR VORTEX XBOX 433 - XBOX SHIPS A DIFFERENT FORMAT, SO VORTEX GETS A PHI EXTENSION THAT SPEAKS THE XBOX FORMAT (Ground: the standing Vortex extension on this PC demands bin x64 Cyberpunk2077 exe at line 9495 of its index js and carries zero xbox tokens, job 428; Tyree photo of the Vortex dialog says the same demand in Vortex own words, Game not found, bin/x64/Cyberpunk2077.exe. The measured Xbox ground, job 417: the game stands at D XboxGames Cyberpunk 2077 with the Content folder holding cpLauncher exe, 84910032 bytes, and no Cyberpunk2077 exe anywhere under D XboxGames. Tyree word: if Xbox does a different format then make a phi extension for Vortex. One, the job reads the standing plugin ground first: the plugin folders under AppData Vortex plugins, the info json of the Cyberpunk plugin whole, and the index js lines that carry registerGame, requiredFiles, executable, and queryPath, capped at 40. Two, the job writes the phi extension as a new plugin beside the standing one, folder game-cyberpunk2077-xbox-phi, with an info json and an index js that registers the game under the phi id, finds the game by the cpLauncher exe standing in the Xbox Content folder at D XboxGames, names cpLauncher exe as the executable and the required file, and deploys mods at the Content root. Three, the job verifies its own writes in the same run: both files stand with sizes, the info json parses, and the index js line count prints. Four, the verdict in one line: PHI EXTENSION PLACED with the folder, the js size, and json ok. The load proof rides Tyree opening Vortex, where the extension stands as its own game entry named Cyberpunk 2077 Xbox Phi. Nothing in the standing plugin is touched and every variable carries the pex433 prefix.) ==='
$pex433plugins = Join-Path $env:APPDATA 'Vortex\plugins'
Write-Output ('PLUGINS DIR: ' + $pex433plugins + ' exists=' + (Test-Path $pex433plugins))
$pex433standing = @(Get-ChildItem $pex433plugins -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*Cyberpunk*' })
foreach ($pex433d in $pex433standing) { Write-Output ('STANDING PLUGIN: ' + $pex433d.Name) }
$pex433info = Join-Path $pex433standing[0].FullName 'info.json'
if (Test-Path $pex433info) { Write-Output '--- STANDING INFO JSON ---'; Get-Content $pex433info | ForEach-Object { Write-Output ('INFO ' + $_) } }
$pex433js = Join-Path $pex433standing[0].FullName 'index.js'
if (Test-Path $pex433js) { $pex433lines = @(Select-String -Path $pex433js -Pattern 'registerGame|requiredFiles|executable|queryPath|GAME_ID|supported' -ErrorAction SilentlyContinue); $pex433lines | Select-Object -First 40 | ForEach-Object { Write-Output ('GROUND ' + $_.LineNumber + ': ' + $_.Line.Trim()) } }
$pex433dir = Join-Path $pex433plugins 'game-cyberpunk2077-xbox-phi'
New-Item -ItemType Directory -Force -Path $pex433dir | Out-Null
$pex433infoOut = Join-Path $pex433dir 'info.json'
$pex433infoObj = [ordered]@{ name = 'Cyberpunk 2077 - Xbox Phi'; author = 'tyofthestarz'; version = '1.0.0'; description = 'Phi extension: teaches Vortex the Xbox Play Anywhere format of Cyberpunk 2077. The game is found by cpLauncher.exe standing in the Xbox Content folder, one game at two addresses.' }
$pex433infoObj | ConvertTo-Json | Set-Content -Path $pex433infoOut -Encoding ASCII
$pex433jsOut = Join-Path $pex433dir 'index.js'
$pex433jsBody = @'
const path = require('path');
const { fs } = require('vortex-api');
const GAME_ID = 'cyberpunk2077xboxphi';
const GAME_NAME = 'Cyberpunk 2077 (Xbox Phi)';
const XBOX_CONTENT_PATH = 'D:/XboxGames/Cyberpunk 2077/Content';
const LAUNCHER_EXE = 'cpLauncher.exe';
function findGame() {
  return fs.statAsync(path.join(XBOX_CONTENT_PATH, LAUNCHER_EXE))
    .then(() => XBOX_CONTENT_PATH)
    .catch(() => undefined);
}
function main(context) {
  context.registerGame({
    id: GAME_ID,
    name: GAME_NAME,
    mergeMods: true,
    queryPath: findGame,
    queryModPath: () => '.',
    executable: () => LAUNCHER_EXE,
    requiredFiles: [LAUNCHER_EXE],
    setup: () => Promise.resolve(),
    environment: {},
    details: {},
  });
  return true;
}
module.exports = { default: main };
'@
Set-Content -Path $pex433jsOut -Value $pex433jsBody -Encoding ASCII
$pex433jsonOk = 0
try { Get-Content $pex433infoOut -Raw | ConvertFrom-Json | Out-Null; $pex433jsonOk = 1 } catch { $pex433jsonOk = 0 }
$pex433jsInfo = Get-Item $pex433jsOut
$pex433jsLines = @(Get-Content $pex433jsOut).Count
Write-Output ('WROTE: ' + $pex433dir)
Write-Output ('INDEX JS LINES=' + $pex433jsLines)
Write-Output ('PHI PEX433 VERDICT: PHI EXTENSION PLACED folder=' + $pex433dir + ' js_bytes=' + $pex433jsInfo.Length + ' json_ok=' + $pex433jsonOk)
Write-Output 'JOB 433 DONE'
```
