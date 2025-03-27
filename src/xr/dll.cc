//
// Created by Raymond on 3/25/2025.
//

#include <lib.hh>
#include <xr/led_pipe.hh>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    initializeLEDPipe();
    return true;
}
