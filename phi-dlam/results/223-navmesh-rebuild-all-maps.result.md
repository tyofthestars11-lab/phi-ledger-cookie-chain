# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:40:51 UTC

## STEP 1
```
=== Tyrees word: ADDRESS THIS FOR BOTH GAMES - the NAVMESH NEEDS TO BE REBUILT banner is stale navigation data: the worlds geometry moved after the last nav build. This job rebuilds navigation in VEILWorld, VEILDistrict and OMNIWorld and saves each map with its fresh Recast data. Route: Python first (NavigationSystemV1 build on the loaded editor world), console command as the second route (RebuildNavigation); every step writes markers to a file, and the saved maps timestamp is the receipt. ===
[2026.10.27-23.40.59:686][  0]LogNavigationDataBuild: Display: UNavigationSystemV1::Build started...
[2026.10.27-23.40.59:686][  0]LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.40.59:689][  0]LogPython: Warning: NAV /Game/Maps/VEILWorld console RebuildNavigation issued
[2026.10.27-23.40.59:805][  0]LogNavigationDataBuild: Display: UNavigationSystemV1::Build started...
[2026.10.27-23.40.59:805][  0]LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.40.59:806][  0]LogPython: Warning: NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
[2026.10.27-23.40.59:836][  0]LogNavigationDataBuild: Display: UNavigationSystemV1::Build started...
[2026.10.27-23.40.59:836][  0]LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.40.59:836][  0]LogPython: Warning: NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
[2026.10.27-23.40.59:877][  0]LogInit: Display: LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.40.59:877][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/VEILWorld console RebuildNavigation issued
[2026.10.27-23.40.59:877][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
[2026.10.27-23.40.59:877][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
VEIL maps run exit: 1
NAV /Game/Maps/VEILWorld loaded
NAV /Game/Maps/VEILWorld nav system: <Object '/Game/Maps/VEILWorld.VEILWorld:NavigationSystemV1_0' (0x0000025B002CD800) Class 'NavigationSystemV1'>
NAV /Game/Maps/VEILWorld python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/VEILWorld console RebuildNavigation issued
NAV /Game/Maps/VEILWorld save_map -> True
NAV /Game/Maps/VEILDistrict loaded
NAV /Game/Maps/VEILDistrict nav system: <Object '/Game/Maps/VEILDistrict.VEILDistrict:NavigationSystemV1_0' (0x0000025B107E4800) Class 'NavigationSystemV1'>
NAV /Game/Maps/VEILDistrict python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
NAV /Game/Maps/VEILDistrict save_map -> True
NAV /Game/Maps/OMNIWorld loaded
NAV /Game/Maps/OMNIWorld nav system: <Object '/Game/Maps/VEILDistrict.VEILDistrict:NavigationSystemV1_0' (0x0000025B107E4800) Class 'NavigationSystemV1'>
NAV /Game/Maps/OMNIWorld python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
NAV /Game/Maps/OMNIWorld save_map -> True
NAV DONE
[2026.10.27-23.41.09:441][  0]LogPython: Warning: NAV /Game/Maps/VEILWorld console RebuildNavigation issued
[2026.10.27-23.41.09:455][  0]LogPython: Warning: NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
[2026.10.27-23.41.09:695][  0]LogNavigationDataBuild: Display: UNavigationSystemV1::Build started...
[2026.10.27-23.41.09:695][  0]LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.41.09:695][  0]LogPython: Warning: NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
[2026.10.27-23.41.09:746][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/VEILWorld console RebuildNavigation issued
[2026.10.27-23.41.09:746][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
[2026.10.27-23.41.09:746][  0]LogInit: Display: LogNavigation: Warning: UNavigationSystemV1::Build Navigation NOT building because navigation build is locked (flags: 0x20).
[2026.10.27-23.41.09:746][  0]LogInit: Display: LogPython: Warning: NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
OMNI maps run exit: 1
NAV /Game/Maps/VEILWorld loaded
NAV /Game/Maps/VEILWorld nav system: <Object '/Temp/Untitled_0.Untitled:NavigationSystemV1_0' (0x0000023E1EE81800) Class 'NavigationSystemV1'>
NAV /Game/Maps/VEILWorld python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/VEILWorld console RebuildNavigation issued
NAV /Game/Maps/VEILWorld save_map -> True
NAV /Game/Maps/VEILDistrict loaded
NAV /Game/Maps/VEILDistrict nav system: <Object '/Game/Maps/VEILWorld.VEILWorld:NavigationSystemV1_0' (0x0000023E1EE81800) Class 'NavigationSystemV1'>
NAV /Game/Maps/VEILDistrict python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/VEILDistrict console RebuildNavigation issued
NAV /Game/Maps/VEILDistrict save_map -> True
NAV /Game/Maps/OMNIWorld loaded
NAV /Game/Maps/OMNIWorld nav system: <Object '/Game/Maps/OMNIWorld.OMNIWorld:NavigationSystemV1_0' (0x0000023E1EE81800) Class 'NavigationSystemV1'>
NAV /Game/Maps/OMNIWorld python build ERROR: 'NavigationSystemV1' object has no attribute 'build'
NAV /Game/Maps/OMNIWorld console RebuildNavigation issued
NAV /Game/Maps/OMNIWorld save_map -> True
NAV DONE
MAP D:\VEIL\Content\Maps\VEILWorld.umap last-write 10/27/2026 5:40:59 PM
MAP D:\VEIL\Content\Maps\VEILDistrict.umap last-write 10/27/2026 5:40:59 PM
MAP D:\OMNI-UE\Content\Maps\OMNIWorld.umap last-write 10/27/2026 5:41:09 PM

```
