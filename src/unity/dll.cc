//
// Created by Raymond on 3/25/2025.
//

#include <lib.hh>
#include <unity/led_pipe.hh>

DWORD WINAPI startLEDPipe() {
    DWORD result = initializeLEDPipe();
    if (result != LedInitializeResult::Success)
        return result;
    accessLEDThread();
    return 0;
}

HANDLE ledPipeThread = nullptr;
void initialize() {
    if (!ledPipeThread)
        ledPipeThread = CreateThread(
            nullptr,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(startLEDPipe),
            nullptr,
            0,
            nullptr
        );
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    // Umm.. let's not do anything in here.
    // I have to use threads and it does NOT like it when you make threads in DllMain for whatever reason
    return true;
}
