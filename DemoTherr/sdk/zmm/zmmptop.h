#pragma once

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif

int ZMM_API zmm_ptop_init();

void ZMM_API zmm_ptop_fini();

int ZMM_API zmm_ptop_down(const char* fpath);

#ifdef __cplusplus
}
#endif
