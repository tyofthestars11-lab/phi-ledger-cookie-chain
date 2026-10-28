# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 04:56:15 UTC

## STEP 1
```
=== STARFIELD MOVE FORENSICS (Tyree 2026-10-27 21:36 MDT: "Which ai? Who moved it?" He installed Starfield on C, never moved it; the Xbox app now registers it to D:\XboxGames, last updated 10/26/2026. The lane record shows staging-folder moves only, never a game move. Windows itself logged every package operation: the AppX deployment log names the operation and its time. Read-only forensics - answer from the machines own record.) ===
--- 1. AppX deployment operations for ProjectGold (newest 25) ---
10/27/2026 21:36:10 | id=472 | Moving package folder \\?\D:\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc to \\?\D:\WindowsApps\Deleted\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwce8008fc7-85e3-4366-966d-f71127
10/27/2026 21:36:10 | id=499 | Removing mounted package folder C:\Program Files\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc. Result: 0x0.
10/27/2026 21:36:10 | id=498 | MSIXVC data source called to remove package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc root \\?\D:\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc successfully.
10/27/2026 21:36:09 | id=400 | Deployment Remove operation with target volume D: on Package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc from: (BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc) finished successfully.
10/27/2026 21:36:09 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0xFFFFFFFF, Set=0x0).
10/27/2026 21:36:09 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x0, Set=0x20).
10/27/2026 21:36:09 | id=855 | Finished resolving action lists. DeploymentRequest action lists: removePackageList: BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc.
10/27/2026 21:36:09 | id=607 | Deployment Remove operation on package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc has been de-queued and is running for user SID S-1-5-21-85939356-3593402667-215545242-1001.
10/27/2026 21:36:09 | id=10002 | Creating Resiliency File C:\ProgramData\Microsoft\Windows\AppRepository\e412cc31-a22b-44cd-895e-cebfdb181ba6_S-1-5-21-85939356-3593402667-215545242-1001_13.rslc for Remove Operation on Package BethesdaSoftworks.ProjectGo
10/27/2026 21:36:09 | id=603 | Started deployment Remove operation on a package with main parameter BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and Options RemoveForAllUsers and 0. See http://go.microsoft.com/fwlink/?LinkId=235160 for 
10/27/2026 20:12:43 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x80, Set=0x0).
10/26/2026 21:11:12 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x80, Set=0x0).
10/26/2026 18:31:52 | id=613 | Performance summary of Deployment Add operation on Package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc: Overall time: 1407 ms (Active time: 1392 ms) Enqueue cost: 79 ms Dequeue delay: 15 ms Bundle pr
10/26/2026 18:31:51 | id=400 | Deployment Add operation with target volume D: on Package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc from: ((DB9969E0-4AC6-4B03-8DC1-AF545F733BE8)) finished successfully.
10/26/2026 18:31:51 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x10000C00, Set=0x0).
10/26/2026 18:31:51 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x20, Set=0x0).
10/26/2026 18:31:51 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x20, Set=0x0).
10/26/2026 18:31:51 | id=5507 | BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc : C:\ProgramData\Microsoft\Windows\AppRepository\Packages\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Resources.????????.pri : No shared merged 
10/26/2026 18:31:51 | id=5507 | BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc : C:\ProgramData\Microsoft\Windows\AppRepository\Packages\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\S-1-5-21-85939356-3593402667-215545242-100
10/26/2026 18:31:51 | id=5507 | BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc : C:\ProgramData\Microsoft\Windows\AppRepository\Packages\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Resources.????????.pri : No shared merged 
10/26/2026 18:31:51 | id=5507 | BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc : C:\ProgramData\Microsoft\Windows\AppRepository\Packages\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\S-1-5-21-85939356-3593402667-215545242-100
10/26/2026 18:31:51 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x0, Set=0x20).
10/26/2026 18:31:51 | id=617 | Successfully updated the status for package BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc and user S-1-5-21-85939356-3593402667-215545242-1001 (Clear=0x0, Set=0x20).
10/26/2026 18:31:50 | id=855 | Finished resolving action lists. DeploymentRequest action lists: addPackageList: BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc.
10/26/2026 18:31:50 | id=574 | Preferred package version for package family is changing. Current preferred version is: NULL. New preferred version will be: BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc.
--- 2. Filesystem birth certificates ---
STARFIELD MOVE FORENSICS DONE

```
