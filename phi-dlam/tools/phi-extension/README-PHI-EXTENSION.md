# PHI EXTENSION (for the Xbox / Game Pass build, via Vortex)
The phi layer in ASI form — the extension format the Game Pass build actually loads.

WHAT IT IS
- phi_extension.asi — a real plugin binary. The Ultimate ASI Loader (already in your Vortex) loads it
  at game start; it writes phi_extension_receipt.txt beside Starfield.exe as its proof of load.
- This is the phi FOUNDATION artifact: the in-game seat the rest of the phi stack reports to.

WHAT IT IS NOT
- Not an SFSE clone. SFSE plugins (Cassiopeia, OSF UI, AISS's engine room) are compiled against SFSE's
  API for the Steam executable; the Store executable is sealed by Microsoft. No shim honestly hosts them.

INSTALL (Vortex)
- Add the zip as a mod; if Vortex asks the installer type (the dialog from tonight), choose
  "Game Pass ASI Loader" — the same answer as the loader itself.
- Launch the game once; phi_extension_receipt.txt appearing beside the game exe = the phi layer loaded.

By TYREE (tyofthestarz) — phi^2 = phi + 1.
