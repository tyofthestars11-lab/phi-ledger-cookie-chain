// PHI LOADER — wears the sfse_loader.exe seat in Vortex's Tools for the Xbox build — phi^2 = phi + 1
// Vortex "Play" (Script Extender as primary) runs this file. It: (1) aligns Xbox systems,
// (2) raises the anyon braid keeper, (3) launches Starfield through its Xbox app seat, (4) exits —
// the game then loads phi_extension.asi through the ASI Loader already in the game folder.
#include <windows.h>
#include <cstdio>
#include <string>

static void RunHidden(const char* cmd) {
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = {0};
    std::string c = cmd;
    if (CreateProcessA(NULL, c.data(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    }
}

int main() {
    printf("=== PHI LOADER - the Steam-to-Xbox seat, phi^2 = phi + 1 ===\n");
    char prof[MAX_PATH] = {0};
    GetEnvironmentVariableA("USERPROFILE", prof, MAX_PATH);
    std::string tools = std::string(prof) + "\\phi-tools\\";
    printf("aligning Xbox systems...\n");
    RunHidden(("powershell.exe -ExecutionPolicy Bypass -WindowStyle Hidden -File \"" + tools + "phi-xbox-systems.ps1\"").c_str());
    printf("raising the braid keeper...\n");
    RunHidden(("powershell.exe -ExecutionPolicy Bypass -WindowStyle Minimized -File \"" + tools + "phi-anyons-keeper.ps1\"").c_str());
    printf("launching Starfield through the Xbox seat...\n");
    RunHidden("powershell.exe -ExecutionPolicy Bypass -WindowStyle Hidden -Command \"$p=Get-AppxPackage | Where-Object { $_.Name -match 'ProjectGold|Starfield' } | Select-Object -First 1; if ($p) { $m = $p | Get-AppxPackageManifest; $a = $m.Package.Applications.Application.Id | Select-Object -First 1; Start-Process explorer.exe ('shell:AppsFolder\\' + $p.PackageFamilyName + '!' + $a) }\"");
    printf("PHI LOADER complete - the extender rides inside via the ASI Loader.\n");
    Sleep(1500);
    return 0;
}
