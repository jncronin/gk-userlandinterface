#ifndef _GK_IOCTLS_H
#define _GK_IOCTLS_H

/* We try not to use ioctls in gk but rather dedicated interfaces, however some
    userland software insists on using it, so handle that here */

struct winsize
{
    unsigned short ws_row;	/* rows, in characters */
    unsigned short ws_col;	/* columns, in characters */
    unsigned short ws_xpixel;	/* horizontal size, pixels */
    unsigned short ws_ypixel;	/* vertical size, pixels */
};

struct sync_merge_data
{
    char name[32];
    int fd2;
    int fence;
    unsigned int flags;
    unsigned int pad;
};

#define TIOCGWINSZ  1
#define TIOCSCTTY   2

#define SYNC_IOC_MERGE      0x00010000

#endif
