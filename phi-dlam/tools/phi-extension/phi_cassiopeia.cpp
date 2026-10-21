// PHI CASSIOPEIA v0.1 — the phi form of the Cassiopeia seat — phi^2 = phi + 1
// Steam Cassiopeia ferries AISS traffic between Papyrus scripts and the backend.
// This ASI build carries the TRANSPORT of that seat on the Game Pass road:
//   game side  phi_request.json  -> courier -> phi_cassiopeia_last_request.json (backend chair reads)
//   PC side    phi_response.json -> courier -> Data\AISS\phi_response.json      (game side reads)
// plus a context heartbeat (phi_context.json) and a full hop log in phi_events.log.
// Named remainder (not faked): registering NEW native functions inside Papyrus itself —
// that binding lives in SFSE's VM interface on Steam; the courier carries everything that moves.
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
    fprintf(f, "[%s] PHI-CASSIOPEIA: %s\n", ts, msg); fclose(f);
}

static bool Slurp(const char* path, char* buf, size_t cap) {
    FILE* f = fopen(path, "rb"); if (!f) return false;
    size_t n = fread(buf, 1, cap - 1, f); fclose(f); buf[n] = 0; return n > 0;
}
static void Spit(const char* path, const char* data) {
    FILE* f = fopen(path, "wb"); if (!f) return; fputs(data, f); fclose(f);
}

static DWORD WINAPI CourierThread(LPVOID) {
    char req[MAX_PATH], lastReq[MAX_PATH], respIn[MAX_PATH], respOut[MAX_PATH], ctx[MAX_PATH], state[MAX_PATH];
    snprintf(req, MAX_PATH, "%sphi_request.json", g_dir);
    snprintf(lastReq, MAX_PATH, "%sphi_cassiopeia_last_request.json", g_dir);
    snprintf(respIn, MAX_PATH, "%sphi_response.json", g_dir);
    snprintf(respOut, MAX_PATH, "%sData\\AISS\\phi_response.json", g_dir);
    snprintf(ctx, MAX_PATH, "%sphi_context.json", g_dir);
    snprintf(state, MAX_PATH, "%sphi_cassiopeia.json", g_dir);
    Spit(state, "{\n  \"seat\": \"PHI CASSIOPEIA v0.1\",\n  \"carries\": [\"request ferry\", \"response ferry\", \"context heartbeat\", \"hop log\"],\n  \"state\": \"courier awake\"\n}\n");
    Stamp("courier awake — ferrying between the game side and the backend chair.");
    static char buf[8192];
    int beat = 0;
    while (g_run) {
        if (Slurp(req, buf, sizeof(buf))) {
            Spit(lastReq, buf); DeleteFileA(req);
            Stamp("request ferried to the backend chair.");
        }
        if (Slurp(respIn, buf, sizeof(buf))) {
            Spit(respOut, buf); DeleteFileA(respIn);
            Stamp("response ferried to the game side (Data\\AISS\\phi_response.json).");
        }
        if (++beat >= 10) {
            beat = 0;
            char c[256]; time_t t = time(NULL);
            snprintf(c, sizeof(c), "{\n  \"heartbeat_unix\": %lld,\n  \"courier\": \"PHI CASSIOPEIA v0.1\",\n  \"state\": \"listening\"\n}\n", (long long)t);
            Spit(ctx, c);
        }
        Sleep(500);
    }
    return 0;
}

static void PhiInit() {
    char exe[MAX_PATH] = {0}; GetModuleFileNameA(NULL, exe, MAX_PATH);
        char* s = strrchr(exe, '\\'); if (s) *(s + 1) = 0; strncpy(g_dir, exe, MAX_PATH - 1);
        CreateThread(NULL, 0, CourierThread, NULL, 0, NULL);
}

extern "C" __declspec(dllexport) void InitializeASI() { PhiInit(); }

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) { DisableThreadLibraryCalls(hModule); /* Ultimate ASI Loader calls InitializeASI outside the loader lock — work lives in PhiInit (ThirteenAG contract). */ }
    if (reason == DLL_PROCESS_DETACH) { g_run = false; }
    return TRUE;
}

