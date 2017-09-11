#pragma once

#include "zmmapi.h"

typedef struct _zmmdraw_handle {
    unsigned unused;
}*zmmdraw_handle;

zmmdraw_handle ZMM_API zmmdraw_new(void*);

int ZMM_API zmmdraw_draw(zmmdraw_handle, unsigned char* buf, unsigned width, unsigned height, int fmt);

void ZMM_API zmmdraw_fini(zmmdraw_handle);

typedef struct {
	unsigned unused;
}*zmmscale_handle;

//////////////////////////////////////////////////////////////////////////

zmmscale_handle ZMM_API zmmscale_new();

int ZMM_API zmmscale_scale(zmmscale_handle, int fmt, 
	unsigned char* srcbuf, int srcwidth, int srcheight,
	unsigned char* dstbuf, int dstwidth, int dstheight);

void ZMM_API zmmscale_fini(zmmscale_handle);