#ifndef __SYS_DIRENT_H
#define __SYS_DIRENT_H

#include <sys/types.h>

struct dirent
{
    ino_t               d_ino;
    off_t               d_off;
    unsigned short      d_reclen;
    unsigned char       d_type;
    char                d_name[256];
};

#define DT_UNKNOWN      0
#define DT_REG          1
#define DT_DIR          2
#define DT_FIFO         5
#define DT_SOCK         6
#define DT_CHR          3
#define DT_BLK          4
#define DT_LNK          7

#endif
