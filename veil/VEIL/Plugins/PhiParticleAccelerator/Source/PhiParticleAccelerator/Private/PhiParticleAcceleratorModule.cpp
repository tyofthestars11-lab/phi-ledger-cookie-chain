#include "Modules/ModuleManager.h"

// The delivered package carried no module entry point anywhere in its
// sources (jobs 207/208: the DLL loads, initialization fails, every
// editor commandlet dies in CoreUObject). A Runtime module needs its
// IMPLEMENT_MODULE; FDefaultModuleImpl is the engine standard when the
// module has no custom startup work.
IMPLEMENT_MODULE(FDefaultModuleImpl, PhiParticleAccelerator)
