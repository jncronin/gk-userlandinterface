#ifndef _GK_GPU_H
#define _GK_GPU_H

#include <stdint.h>

#define GK_PIXELFORMAT_ARGB8888     0
#define GK_PIXELFORMAT_RGB888       1
#define GK_PIXELFORMAT_RGB565       2
#define GK_PIXELFORMAT_L8           5
#define GK_PIXELFORMAT_XRGB8888     (((GK_PIXELFORMAT_RGB888) << 8) | (GK_PIXELFORMAT_ARGB8888))

enum gpu_message_type
{
    FlipBuffers,
    SetBuffers,
    BlitColor,
    BlitImage,
    CleanCache,
    SignalThread,
    ClearScreen,
    SetScreenMode,
    FlipScaleBuffers,
    BlitImageNoBlend,
    InvalidateCache,


    gpu_message_type_last = 2147483647  // force enum to 4 bytes
};

struct gpu_message
{
    enum gpu_message_type type;
    uint32_t dest_addr;
    uint32_t src_addr_color;
    uint32_t dest_pf;
    uint32_t src_pf;
    uint16_t dx, dy, sx, sy, w, h, dp, sp, dw, dh;
};

#endif
