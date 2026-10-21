Scriptname CassiopeiaPapyrusExtender Hidden
{PHI CASSIOPEIA — the shim seat. Same name, same doors as the original extender's
 Papyrus face; the hands behind them are phi: Papyrus + the ferry + the voice.
 Signatures for the AISS-critical pair are grounded in the original's changelog
 (v4.0). The full census completes from the original .psc when it reaches the vault.}

; --- THE AISS DOOR ------------------------------------------------------------
; Original (native): opens the text input menu; the typed string returns through
; the custom event TextInputMenu_EndEditText.
Function OpenTextInputMenu() Global
    Debug.Trace("PHI-AISS OPEN-TEXT-INPUT")
    ; The PC seat hears this line in the Papyrus log and opens push-to-talk.
    ; When TYREE's words return through the ferry, the seat speaks the reply and
    ; this seat fires TextInputMenu_EndEditText with the text, as the original did.
EndFunction

; --- TIME UTILITIES (pure Papyrus — the original's stamps, carried) -----------
Int Function GenerateTimeStamp() Global
    Return 0 ; completed against the original .psc signature pass
EndFunction

Bool Function IsTimeStampValid(Int aiStamp) Global
    Return aiStamp > 0
EndFunction
