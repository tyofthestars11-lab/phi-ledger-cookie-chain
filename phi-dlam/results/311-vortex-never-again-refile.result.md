# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 05:13:30 UTC

## STEP 1
```
=== VORTEX NEVER-AGAIN - REFILE of job 297 (297 died on a ParserError before executing; nothing ran under it. Pure ASCII refile. Tyree 2026-10-27 22:30 MDT: make sure Vortex never does that again - the 48 GB Witcher warehouse happened because Vortex downloads defaulted to C:\Users\Admin\AppData\Roaming\Vortex\downloads. This job: (1) creates D:\Vortex Downloads; (2) reports whether Vortex is running; (3) reports Vortex current C footprint as the guard baseline; (4) scans small files in the Vortex roaming folder for download-path setting candidates and prints them. It does NOT edit Vortex settings store blind and does NOT move any game files (Tyree ask-first clause, 2026-10-27 22:31 MDT) - the repoint happens only if a plainly writable setting is found and printed; otherwise the exact setting terrain is reported for the record.) ===
Vortex running: False
Vortex C footprint now: 1.44 GB (post-Witcher baseline; guard line: report if it ever passes 3 GB again)
SETTING CANDIDATE: C:\Users\Admin\AppData\Roaming\Vortex\flag-cache.json
{"timestamp":1793158864651,"toggles":[{"name":"sta-407-premium-collection-social-proof-upsell","enabled":true,"variant":{"name":"b","enabled":true,"payload":null},"impression_data":false,"impressionData":false},{"name":"sta-771-jp-lower-pricing","enabled":true,"variant":{"name":"control","enabled":t
SETTING CANDIDATE: C:\Users\Admin\AppData\Roaming\Vortex\vortex.log
2026-10-27T15:37:35.418Z [INFO] [MAIN] download concurrency changed {"from":1,"to":1}
2026-10-27T15:37:35.418Z [INFO] [MAIN] download bandwidth limit removed 
2026-10-27T15:37:35.429Z [DEBG] [RENDERER] register test {"id":"verify-downloads-transfers","eventType":"gamemode-activated"}
SETTING CANDIDATE: C:\Users\Admin\AppData\Roaming\Vortex\vortex1.log
2026-08-24T04:58:37.755Z [DEBG] [RENDERER] start download {}
2026-08-24T04:58:37.755Z [INFO] [RENDERER] start download mod {"urlStr":"nxm://newvegas/mods/66589/files/1000052437?key=2wVfhroNP3_-CD38i7puPQ&expires=1787720317&user_id=287901737"}
2026-08-24T04:58:38.005Z [DEBG] [RENDERER] starting download {"encodedUrl":{"url":"nxm://newvegas/mods/66589/files/1000052437?key=2wVfhroNP3_-CD38i7puPQ&expires=1787720317&user_id=287901737"},"dest":"C:\\Users\\Admin\\AppData\\Roaming\\Vortex\\downloads\\falloutnv\\__vortex_tmp_00000014","collationI
SETTING CANDIDATE: C:\Users\Admin\AppData\Roaming\Vortex\vortex2.log
2026-08-06T00:05:44.259Z [DEBG] [MAIN] unkown feature flag returned by Unleash API {"flagName":"unified-mod-download-modal"}
2026-08-06T00:05:44.259Z [DEBG] [MAIN] unkown feature flag returned by Unleash API {"flagName":"in-browser-download-manager"}
2026-08-06T00:05:44.259Z [DEBG] [MAIN] unkown feature flag returned by Unleash API {"flagName":"in-browser-opfs-download-manager"}
SETTING CANDIDATE: C:\Users\Admin\AppData\Roaming\Vortex\vortex3.log
2026-05-20T06:44:30.892Z [INFO] [RENDERER] init extension {"name":"download_management","path":"C:\\Program Files\\Vortex\\resources\\app.asar\\extensions\\download_management"}
2026-05-20T06:44:31.474Z [DEBG] [RENDERER] register test {"id":"verify-downloads-transfers","eventType":"gamemode-activated"}
2026-05-20T06:44:31.551Z [DEBG] [RENDERER] once {"extension":"download_management"}
VORTEX NEVER-AGAIN READ DONE

```
