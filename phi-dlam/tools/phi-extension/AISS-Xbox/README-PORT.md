# AISS-Xbox — the PC Game Pass port (blueprint: Manus, 2026-10-20; build: Golden Ratio Muse)
Steam:  Starfield.exe -> SFSE -> Cassiopeia -> AISS scripts -> AISS_Backend.exe
Xbox:   Starfield.exe -> Ultimate ASI Loader -> PHI AISS BRIDGE -> AISS_Backend.exe (UNCHANGED)

SHARED (identical both builds): x2357aiss.esm - AISS Papyrus scripts (common APIs) -
Data\AISS\config.json - character profiles/addons - AISS_Backend.exe - provider config
(OpenRouter / Player2 / LM Studio local 127.0.0.1:1234).

REPLACED (Xbox package only): the SFSE/Cassiopeia native bridge -> phi_aiss_bridge.asi.
No sfse_loader.exe requirement in THIS package's manifest naming: Vortex's SFSE tool seat is
the phi loader (separate artifact); this bridge rides the ASI Loader already in the game folder.

STATUS v0.1 (compiled, sha in vault): transport + contract layer LIVE — blackboard state file,
event log, outbox poll loop (player text -> bridge). 
REMAINDERS (named terrain, not faked): (1) Papyrus-side native binding — Cassiopeia's seat;
on the Store build this is the deep water of the port. (2) Store-exe context addresses
(active NPC / quest / location reads) — unpublished for the sealed binary.
Vortex setup note (blueprint): game location C:\XboxGames\Starfield\Content set manually +
data-folder junction enabled — matches TYREE's install (C:\XboxGames).
