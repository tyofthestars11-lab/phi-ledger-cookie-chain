// PHI EXTENDER v2 — the phi host inside the Xbox/Game Pass build — phi^2 = phi + 1
// Loads via the ASI Loader. On load: (1) receipt, (2) phi plugin chain (phi_plugins/*.asi, in name order),
// (3) the blackboard — phi_blackboard.json + phi_events.log beside the game exe, the two-way seat
// between the game and the phi stack on the PC side.
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

static char g_dir[MAX_PATH] = {0};

static void Stamp(const char* msg) {
    char out[MAX_PATH]; snprintf(out, MAX_PATH, "%sphi_events.log", g_dir);
    FILE* f = fopen(out, "a"); if (!f) return;
    time_t t = time(NULL); char ts[64]; strftime(ts, 64, "%Y-%m-%d %H:%M:%S", localtime(&t));
    fprintf(f, "[%s] %s\n", ts, msg); fclose(f);
}

static void WriteBlackboard(int chainCount) {
    char out[MAX_PATH]; snprintf(out, MAX_PATH, "%sphi_blackboard.json", g_dir);
    FILE* f = fopen(out, "w"); if (!f) return;
    time_t t = time(NULL);
    fprintf(f, "{\n  \"host\": \"PHI EXTENDER v2\",\n  \"law\": \"phi^2 = phi + 1\",\n  \"loaded_at_unix\": %lld,\n  \"chain_plugins_loaded\": %d,\n  \"seat\": \"game <-> phi stack (tyree model, companions, bridge)\",\n  \"state\": \"awake\"\n}\n", (long long)t, chainCount);
    fclose(f);
}

static int LoadChain() {
    char pat[MAX_PATH]; snprintf(pat, MAX_PATH, "%sphi_plugins\\*.asi", g_dir);
    WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return 0;
    std::vector<std::string> names;
    do { if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) names.push_back(fd.cFileName); } while (FindNextFileA(h, &fd));
    FindClose(h);
    std::sort(names.begin(), names.end());
    int ok = 0;
    for (auto& n : names) {
        char full[MAX_PATH]; snprintf(full, MAX_PATH, "%sphi_plugins\\%s", g_dir, n.c_str());
        if (LoadLibraryA(full)) { ok++; char m[512]; snprintf(m, 512, "chain loaded: %s", n.c_str()); Stamp(m); }
        else { char m[512]; snprintf(m, 512, "chain FAILED to load: %s", n.c_str()); Stamp(m); }
    }
    return ok;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        char exe[MAX_PATH] = {0}; GetModuleFileNameA(NULL, exe, MAX_PATH);
        char* s = strrchr(exe, '\\'); if (s) *(s + 1) = 0; strncpy(g_dir, exe, MAX_PATH - 1);
        Stamp("PHI EXTENDER v2 loaded via ASI Loader - phi^2 = phi + 1 - the host is awake.");
        int n = LoadChain();
        WriteBlackboard(n);
        char m[256]; snprintf(m, 256, "blackboard open - chain plugins loaded: %d", n); Stamp(m);
    }
    return TRUE;
}
