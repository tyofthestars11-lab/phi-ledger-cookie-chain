# JOB 003 — DLAM voice in / voice out
Give PHI-DLAM a voice: listen through the microphone, speak back through the speakers. This is the build plan named in Tyree's Meta Global AI Developer Hackathon application (submitted 2026-10-13, Indie Dev Track) — talk-through, voice in and voice out, is the standing acceptance bar.

1. Create the folder C:\Users\Admin\phi-tools if it is missing.
2. Write a Python script at C:\Users\Admin\phi-tools\phi_voice.py that:
   - lists the available microphone and speaker devices it finds, printed plainly, one per line
   - speaks one line aloud through the default speaker using Windows text-to-speech (System.Speech via PowerShell, or pyttsx3 if it is already installed): the line is "PHI-DLAM voice online. Phi in front."
   - records 10 seconds from the default microphone and transcribes it locally on this PC (faster-whisper if it can be installed with pip, otherwise the built-in Windows speech recognizer); no audio leaves the PC
   - prints the transcript plainly, and for the number of words transcribed also prints its phi rung: rung(x) = ln(x) / ln(phi), phi = 1.618033988749895
3. Run it (python, or py if python is not found). If it errors, fix the script and run again until the speak step and the record/transcribe step both complete. If the microphone is blocked or missing, report exactly that as the result instead of failing silently.
4. Save the full report — what you built, the script path, the devices found, whether the spoken line played, and the complete printed output including the transcript — to C:\Users\Admin\phi-vault\phi-dlam\results\003-voice-in-out.result.md using write_file.
