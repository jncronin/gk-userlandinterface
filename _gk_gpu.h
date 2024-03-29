#ifndef _GK_GPU_H
#define _GK_GPU_H

#include <stdint.h>

enum gpu_message_type
{
    FlipBuffers,
    SetBuffers,
    BlitColor,
    BlitImage,
    CleanCache,
    SignalThread
};

struct gpu_message
{
    enum gpu_message_type type;
    uint32_t dest_addr;
    uint32_t src_addr_color;
    uint32_t dest_pf;
    uint32_t src_pf;
    uint32_t nlines, row_width;
    int dest_fbuf_relative;
};

#endif
