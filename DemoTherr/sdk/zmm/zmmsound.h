#pragma once

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void* ZMM_API zmm_sound_init();

int ZMM_API zmm_sound_put(void* handle, void* fmt, unsigned char* buf, unsigned len, unsigned timestamp);

void ZMM_API zmm_sound_fini(void* handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */
