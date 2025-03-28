//
// Created by Raymond on 3/28/2025.
//

#ifndef EXPORTS_HH
#define EXPORTS_HH

#include <lib.hh>

extern "C" {
    __declspec(dllexport) uint16_t chuni_io_get_api_version(void);
    __declspec(dllexport) HRESULT chuni_io_jvs_init(void);
};

#endif //EXPORTS_HH
