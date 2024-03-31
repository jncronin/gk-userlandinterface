#ifndef __GK_PROCCREATE_H
#define __GK_PROCCREATE_H

#define GK_MAX_OPEN_FILES      16

struct proccreate_t
{
    int acquire_fds[GK_MAX_OPEN_FILES];
    uint32_t heap_size;
    unsigned int core_mask;
    unsigned int prefer_core_mask;
    unsigned int with_focus;
    unsigned int pixel_format;
};

#endif
