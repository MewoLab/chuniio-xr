//
// Created by Raymond on 3/28/2025.
//

#include <lib.hh>
#include <io/exports.hh>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    return true;
}

// Common exports (x86 and x64)

uint16_t chuni_io_get_api_version(void) {
    return 0x0102;
};
HRESULT chuni_io_jvs_init(void) {
    return S_OK;
}