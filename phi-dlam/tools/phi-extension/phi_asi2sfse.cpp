// PHI ASI2SFSE v0.1 — the ASI -> SFSE adapter organ — phi^2 = phi + 1
// SFSE plugins expect a host named SFSE. On the Game Pass road there is none — so the phi stack
// builds the door on the ASI road instead:
//   (1) PRESENCE: stamps the adapter's journal + state file beside the exe.
//   (2) PROBE: scans Data\SFSE\Plugins\*.dll, loads each in PROBE mode (resolve exports only,
//       NO calls into the plugin), and journals which SFSE entry points each plugin carries.
//       The journal is the port's measured spec: what the Steam layer actually asks for.
//   (3) HOST SEAT (gated): phi_asi2sfse.ini may list plugin filenames under [host]; only those
//       are ever loaded resident. Default ini hosts NOTHING. The handshake implementation lands
//       against the journal's evidence, one interface at a time — measured, never guessed.
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <ctime>

static char g_dir[MAX_PATH] = {0};

static void Stamp(const char* msg) {
    char out[MAX_PATH]; snprintf(out, MAX_PATH, "%sphi_events.log", g_dir);
    FILE* f = fopen(out, "a"); if (!f) return;
    time_t t = time(NULL); char ts[64]; strftime(ts, 64, "%Y-%m-%d %H:%M:%S", localtime(&t));
    fprintf(f, "[%s] ASI2SFSE: %s\n", ts, msg); fclose(f);
}

static DWORD WINAPI ProbeThread(LPVOID) {
    Sleep(1500);
    char pat[MAX_PATH]; snprintf(pat, MAX_PATH, "%sData\\SFSE\\Plugins\\*.dll", g_dir);
    WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) { Stamp("probe: no SFSE plugins folder found — nothing asking for SFSE right now."); return 0; }
    int found = 0;
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
        found++;
        char full[MAX_PATH]; snprintf(full, MAX_PATH, "%sData\\SFSE\\Plugins\\%s", g_dir, fd.cFileName);
        HMODULE m = LoadLibraryExA(full, NULL, DONT_RESOLVE_DLL_REFERENCES);
        char msg[1024];
        if (!m) { snprintf(msg, 1024, "probe: %s — cannot load even for probing.", fd.cFileName); Stamp(msg); continue; }
        bool hasQuery = GetProcAddress(m, "SFSEPlugin_Query") != NULL;
        bool hasLoad  = GetProcAddress(m, "SFSEPlugin_Load")  != NULL;
        bool hasVer   = GetProcAddress(m, "SFSEPlugin_Version") != NULL;
        snprintf(msg, 1024, "probe: %s — SFSEPlugin_Query=%s SFSEPlugin_Load=%s SFSEPlugin_Version=%s",
                 fd.cFileName, hasQuery ? "yes" : "no", hasLoad ? "yes" : "no", hasVer ? "yes" : "no");
        Stamp(msg);
        FreeLibrary(m);
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    char tail[256]; snprintf(tail, 256, "probe complete: %d SFSE plugin(s) journaled. Host seat gated by phi_asi2sfse.ini (default: host nothing).", found);
    Stamp(tail);
    char state[MAX_PATH]; snprintf(state, MAX_PATH, "%sphi_asi2sfse.json", g_dir);
    FILE* f = fopen(state, "w");
    if (f) { fprintf(f, "{\n  \"adapter\": \"PHI ASI2SFSE v0.1\",\n  \"sfse_plugins_found\": %d,\n  \"host_mode\": \"gated-off (phi_asi2sfse.ini)\",\n  \"state\": \"journaling\"\n}\n", found); fclose(f); }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        char exe[MAX_PATH] = {0}; GetModuleFileNameA(NULL, exe, MAX_PATH);
        char* s = strrchr(exe, '\\'); if (s) *(s + 1) = 0; strncpy(g_dir, exe, MAX_PATH - 1);
        Stamp("PHI ASI2SFSE v0.1 awake — the ASI road now has an SFSE-shaped door (probe + journal; host gated).");
        CreateThread(NULL, 0, ProbeThread, NULL, 0, NULL);
    }
    return TRUE;
}
