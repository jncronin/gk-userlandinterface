#ifndef _GK_GPU_H
#define _GK_GPU_H

#include <stdint.h>

#if __GAMEKID__ == 4
#define GK_PIXELFORMAT_ARGB8888     0
#define GK_PIXELFORMAT_ABGR8888     1
#define GK_PIXELFORMAT_RGBA8888     2
#define GK_PIXELFORMAT_BGRA8888     3
#define GK_PIXELFORMAT_RGB565       4
#define GK_PIXELFORMAT_BGR565       5
#define GK_PIXELFORMAT_RGB888       6
#define GK_PIXELFORMAT_XRGB8888     7
#define GK_PIXELFORMAT_L8           8
#define GK_PIXELFORMAT_A8L8         9
#define GK_PIXELFORMAT_A4L4         10
#define GK_PIXELFORMAT_ARGB1555     11
#define GK_PIXELFORMAT_ARGB4444     12
#define GK_PIXELFORMAT_RGB565A8     13

#define GK_PIXELFORMAT_MAX          13
#else
#define GK_PIXELFORMAT_ARGB8888     0
#define GK_PIXELFORMAT_RGB888       1
#define GK_PIXELFORMAT_RGB565       2
#define GK_PIXELFORMAT_ARGB1555     3
#define GK_PIXELFORMAT_ARGB4444     4
#define GK_PIXELFORMAT_L8           5
#define GK_PIXELFORMAT_XRGB8888     (((GK_PIXELFORMAT_RGB888) << 8) | (GK_PIXELFORMAT_ARGB8888))
#endif

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
    SetBlitPalette,
    BlitImageNoBlendIf,


    gpu_message_type_last = 2147483647  // force enum to 4 bytes
};

#if __GAMEKID__ == 4
struct gpu_message
{
    uintptr_t dest_addr;
    uintptr_t src_addr_color;
    enum gpu_message_type type;
    uint32_t dest_pf;
    uint32_t src_pf;
    uint16_t dx, dy, sx, sy, w, h, dp, sp, dw, dh;
};
#else
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

#endif
