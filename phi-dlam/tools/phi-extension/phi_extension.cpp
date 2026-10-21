// PHI EXTENSION — the phi layer in ASI form — loads through the Game Pass ASI Loader
// On load: writes its receipt beside the game exe. Proof of load, phi^2 = phi + 1.
#include <windows.h>
#include <cstdio>
#include <ctime>

static void WriteReceipt() {
    char exePath[MAX_PATH] = {0};
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    char* slash = strrchr(exePath, '\\');
    if (slash) *(slash + 1) = 0;
    char out[MAX_PATH];
    snprintf(out, MAX_PATH, "%sphi_extension_receipt.txt", exePath);
    FILE* f = fopen(out, "a");
    if (!f) return;
    time_t t = time(NULL);
    char ts[64]; strftime(ts, 64, "%Y-%m-%d %H:%M:%S", localtime(&t));
    fprintf(f, "[%s] PHI EXTENSION loaded via ASI Loader - phi^2 = phi + 1 - the phi layer is in the game.\n", ts);
    fclose(f);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        WriteReceipt();
    }
    return TRUE;
}
