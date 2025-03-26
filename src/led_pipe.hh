//
// Created by Raymond on 3/25/2025.
//

#ifndef LED_PIPE_HH
#define LED_PIPE_HH

#include <lib.hh>

#define LED_BILLBOARD_COUNT (110 * 3)

enum LedInitializeResult: int {
    Success,
    DoesntExist,
    AccessDenied,
    AlreadyExists,
};

int initializeLEDPipe();

extern "C" __declspec(dllexport)
void getBillboardLEDs(int* buffer);

#endif //LED_PIPE_HH
