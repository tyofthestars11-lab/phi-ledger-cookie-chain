# VEIL lag floaters fix, via GitHub DLAM, no job work mess

Photo proof 2026-10-31, editor open, new engine worked, game playing:
- First photo: FPS 8.3 / 120.6 ms, Mem 4699.57 mb, Objs 81181, Stalls 2, AssetRegistryGather 49.2157s, Uncontrolled assets 22452, NumUncachedFiles 22524, Warning Invalid duplicate copies of ExternalActor ThirdPersonMap.
- Second photo: FPS 24.3 / 41.2 ms, Mem 5199, play live, character on floor.
- Census: tall actors 97, floaters 31.
- Normal pillars: StaticMeshActor 60, 62, 64, 66 base 56.0 height 700.0.
- Floaters to ground or remove: StaticMeshActor 456 base 406365.7 height 1940709.5, 468 same, 467 base 108025.3 height 90068.1, 469 base 1501.4 height 68587.7, 457 base 1501.4 height 53346.0, 460 base 1677.3 height 26230.4, 461 base 1767.4 height 1862.3, 462 base 1470.5 height 11070.0, 463 base 1813.0 height 4130.6, 464 base 1557.6 height 12749.1, 465 base 1700.0 height 2676.0, 466 base 1518.1 height 10895.0.
- Fix: delete duplicate ThirdPersonMap ExternalActor copies, ground floaters to floor 1618 or remove if duplicate, save map over 766528, verify FPS up, stalls down, floaters 0.
- This is a GitHub DLAM fix document, not a job file. No job work mess. Tyree types nothing. GitHub goes to PC on its own.
- Proof is PC only: next photo shows FPS, floaters count, map saved. Filed, not fixed, until that shows.
