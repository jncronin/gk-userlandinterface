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


#endif
