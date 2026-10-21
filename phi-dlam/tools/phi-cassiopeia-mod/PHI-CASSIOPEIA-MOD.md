# PHI CASSIOPEIA — THE MOD (v0.1 spec + skeleton) — phi^2 = phi + 1
TYREE's word, 2026-10-21: "we need to make a mod that is a cassiopeia papyrus extender."

## WHAT THE ORIGINAL IS (source-verified, allmods changelog mirror)
Cassiopeia Papyrus Extender = SFSE plugin + Papyrus script (CassiopeiaPapyrusExtender.psc)
registering NATIVE Papyrus functions + custom events. AISS's chat door is two of them:
  - OpenTextInputMenu()                     (added Cassiopeia v4.0)
  - TextInputMenu_EndEditText(String) event (added Cassiopeia v4.0)
Wider census from its changelogs (v3.1-v6.3): GetFileSizeKB, GenerateTimeStamp /
IsTimeStampValid / GetElapsedTimeSinceTimeStamp / RenewTimeStamp, log/log2/log10,
NavigateToPlanet, Jump / CalculateJumpHeight / GetVelocity, GetActorAlpha /
ActorFadeOut / ActorFadeIn, SetFirstPersonModelVisible, AddRefsToRefColl,
ReleasePapyrusObjects, GetAllRefsLinkedToMe, GetNthItemReference, GetWorkshopName,
GetFormTypeIntAsStr / GetFormTypeStrAsInt, IsInSameSpace, HasAnyVMScript /
HasAllVMScripts, GetSpaceshipParts, IsOutpostBeacon, GetPlayerFollowerCount,
CanPlayerPilotShip, PlacePackInAtCoordinates, PathToPoint, GetAttachToRef +
events TESFurnitureEvent, BGSLocationLoadedEvent, TESFormDeleteEvent,
TESObjectLoadedEvent, ActorCellChangeEvent, ReferenceSet3d. Full signature list
lives in the original .psc — which sits in TYREE's Vortex staging folder on his PC
(Data\Scripts\Source\). That file is the exact spec; it rides to the vault when it rides.

## THE PHI FORM — A SHIM, NOT A PORT OF THE DLL
Papyrus dispatches calls by script name + function name at runtime. A phi script
named CassiopeiaPapyrusExtender carrying same-name, same-signature functions
receives the calls AISS compiled against the native declarations. The native DLL
never exists; the seat is filled by Papyrus itself + the phi organs already built
(extender, courier, ASI2SFSE, voice).

## THE TALK LOOP (closes on stock surfaces — no SFSE anywhere)
1. AISS topic fires -> shim OpenTextInputMenu() -> Debug.Trace("PHI-AISS OPEN ...")
   writes the Papyrus log line (the one outbound channel stock Papyrus owns).
2. The PC seat (phi-voice v2 watcher) reads the log line -> push-to-talk opens:
   TYREE speaks (the companions' System.Speech recognition, already proven).
3. Seat composes the NPC reply (local tyree model; context from the traced line:
   speaker, cell, quest stage — everything the script can name, it can Trace).
4. phi-voice SPEAKS the reply + shows it in the caption window on the TV.
5. Shim fires TextInputMenu_EndEditText with the spoken text, so AISS's own
   bookkeeping (profiles, memory) receives exactly what the original would deliver.
Named remainder, kept named: in-game TYPED text entry (a real keyboard box inside
the game UI) still waits on the Store-exe VM addresses — the census organ's road.
Voice-first is not the consolation; it is TYREE's stated bar (talk-through, like
the companions).

## PACKAGE SHAPE (Vortex-ready, per the Manus layout)
phi-cassiopeia-mod/
  PHI-CASSIOPEIA-MOD.md          (this spec)
  Source/CassiopeiaPapyrusExtender.psc   (the shim — signatures completed from the
                                          original .psc when it reaches the vault)
  phi-voice.ps1 (v2, captions)   (in phi-dlam/tools — the seat half of the loop)

## STATE
v0.1: spec + shim skeleton + voice v2. Awaiting two files from TYREE's PC to finish
the exact build: CassiopeiaPapyrusExtender.psc (signatures) and AISS's scripts
(the call census). Both are terrain, stated once.
