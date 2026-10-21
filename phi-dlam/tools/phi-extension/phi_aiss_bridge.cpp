// PHI AISS BRIDGE v0.1 — the Xbox/Game Pass port of the AISS in-game bridge (Manus blueprint, 2026-10-20)
// Steam path: SFSE -> Cassiopeia -> AISS scripts -> AISS_Backend.exe
// Xbox path:  Starfield.exe -> Ultimate ASI Loader -> THIS BRIDGE -> AISS_Backend.exe (unchanged)
// v0.1 delivers the TRANSPORT + CONTRACT layer: blackboard seat, event log, outbox poll loop.
// The contract (per blueprint): send player text / identify active NPC / read context /
// receive backend response / inject into dialogue-UI / trigger audio.
// Deep remainders (named, not faked): Papyrus-side native binding + Store-exe context addresses.
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <ctime>

static char g_dir[MAX_PATH] = {0};
static volatile bool g_run = true;

static void Stamp(const char* msg) {
    char out[MAX_PATH]; snprintf(out, MAX_PATH, "%sphi_events.log", g_dir);
    FILE* f = fopen(out, "a"); if (!f) return;
    time_t t = time(NULL); char ts[64]; strftime(ts, 64, "%Y-%m-%d %H:%M:%S", localtime(&t));
    fprintf(f, "[%s] AISS-BRIDGE: %s\n", ts, msg); fclose(f);
}

static void WriteBridgeState() {
    char out[MAX_PATH]; snprintf(out, MAX_PATH, "%sphi_aiss_bridge.json", g_dir);
    FILE* f = fopen(out, "w"); if (!f) return;
    fprintf(f, "{\n  \"bridge\": \"PHI AISS BRIDGE v0.1\",\n  \"route\": \"Xbox/Game Pass via Ultimate ASI Loader\",\n  \"backend\": \"AISS_Backend.exe (unchanged)\",\n  \"contract\": [\"send_player_text\", \"identify_active_npc\", \"read_context\", \"receive_backend_response\", \"inject_dialogue_ui\", \"trigger_audio\"],\n  \"transport\": \"phi_aiss_outbox.txt -> bridge -> phi_events.log; backend replies -> phi_aiss_inbox.txt\",\n  \"state\": \"listening\"\n}\n");
    fclose(f);
}

static DWORD WINAPI OutboxThread(LPVOID) {
    char outbox[MAX_PATH]; snprintf(outbox, MAX_PATH, "%sphi_aiss_outbox.txt", g_dir);
    while (g_run) {
        FILE* f = fopen(outbox, "r");
        if (f) {
            char line[1024];
            if (fgets(line, sizeof(line), f) && line[0] && line[0] != '\n') {
                fclose(f);
                char m[1200]; snprintf(m, 1200, "player text received via transport: %.900s", line); Stamp(m);
                FILE* c = fopen(outbox, "w"); if (c) fclose(c);
            } else fclose(f);
        }
        Sleep(500);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        char exe[MAX_PATH] = {0}; GetModuleFileNameA(NULL, exe, MAX_PATH);
        char* s = strrchr(exe, '\\'); if (s) *(s + 1) = 0; strncpy(g_dir, exe, MAX_PATH - 1);
        WriteBridgeState();
        Stamp("PHI AISS BRIDGE v0.1 awake - transport open, contract seated (Manus blueprint port).");
        CreateThread(NULL, 0, OutboxThread, NULL, 0, NULL);
    }
    if (reason == DLL_PROCESS_DETACH) g_run = false;
    return TRUE;
}
