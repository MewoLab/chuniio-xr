//
// Created by Raymond on 3/25/2025.
//


#include <unity/led_pipe.hh>

HANDLE pipe;
const auto pipeName = TEXT("\\\\.\\pipe\\chuni_led");

unsigned char* billboardBuffer = static_cast<unsigned char*>(malloc(LED_BILLBOARD_COUNT));
unsigned char* sliderBuffer = static_cast<unsigned char*>(malloc(LED_SLIDER_COUNT));

unsigned char readNextByte() {
    unsigned char byte = 0;
    if (!ReadFile(pipe, &byte, 1, nullptr, nullptr)) {
        CloseHandle(pipe);
        pipe = nullptr;
        initializeLEDPipe();
    }
    return byte;
};
int gammaCorrect(int v) {
    return pow(v, 2.2f);
}

DWORD WINAPI accessLEDThread() {
    while (true) {
        std::vector<unsigned char> buffer;
        int currentBoard = -1;

        unsigned char byte = readNextByte();
        currentBoard = static_cast<int>(byte);
        while (true) {
            byte = readNextByte();
            if (byte == 0xE0)
                break;
            if (byte == 0xD0)
                byte = readNextByte() + 1;
            buffer.push_back(byte);
        };

        switch (currentBoard) {
            // TODO: handle partition LEDs
            // TODO: handle slider LEDs
            case 0:
                memcpy(billboardBuffer, buffer.data(), buffer.size() - (3 * 3)); break;
            case 1:
                memcpy(billboardBuffer + (50 * 3), buffer.data(), buffer.size() - (3 * 3)); break;
            case 2:
                memcpy(sliderBuffer, buffer.data(), buffer.size()); break;
            default: break;
        }
        buffer.clear();
        std::vector<unsigned char>().swap(buffer); // delete all instances
    };
    return 0;
};

DWORD initializeLEDPipe() {
    if (pipe) return LedInitializeResult::AlreadyExists;

    SECURITY_ATTRIBUTES securityAttributes;
    securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
    securityAttributes.lpSecurityDescriptor = nullptr;
    securityAttributes.bInheritHandle = true;

    while (true) {
        pipe = CreateFile(pipeName, GENERIC_READ | FILE_WRITE_ATTRIBUTES, 0, &securityAttributes, OPEN_EXISTING, 0, nullptr);
        if (pipe != INVALID_HANDLE_VALUE)
            break;
        CloseHandle(pipe);
        printf("Failed to connect to LED pipe.\n");
        Sleep(1000);
    };

    printf("Connected to LED pipe.\n");

    DWORD pipeMode = PIPE_READMODE_BYTE;
    if (!SetNamedPipeHandleState(pipe, &pipeMode, nullptr, nullptr)) {
        printf("Failed to set pipe mode.\n");
        return LedInitializeResult::AccessDenied;
    };

    return LedInitializeResult::Success;
}

void getBillboardLEDs(int* buffer) {
    for (int i = 0; i < LED_BILLBOARD_COUNT; i++)
        buffer[i] = gammaCorrect(static_cast<int>(billboardBuffer[i]));
}

void getSliderLEDs(int* buffer) {
    for (int i = 0; i < LED_SLIDER_COUNT; i++)
        buffer[i] = gammaCorrect(static_cast<int>(sliderBuffer[i]));
}