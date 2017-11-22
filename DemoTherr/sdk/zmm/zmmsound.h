#pragma once

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    ZMM_API void* zmm_sound_init();

    ZMM_API int zmm_sound_put(void* handle, void* fmt, unsigned char* buf, unsigned len, unsigned timestamp);

    ZMM_API void zmm_sound_fini(void* handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */
