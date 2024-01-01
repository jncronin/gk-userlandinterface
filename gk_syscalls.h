#ifndef GKSYSCALLS_H
#define GKSYSCALLS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <sys/stat.h>

struct gk_syscalls
{
    /* newlib libgloss syscalls */
    int (*_close)(int file);
    int (*_execve)(char *name, char **argv, char **env);
    void (*_exit)(int rc);
    int (*_fork)();
    int (*_fstat)(int file, struct stat *st);
    int (*_getpid)();
    int (*_isatty)(int file);
    int (*_kill)(int pid, int sig);
    int (*_link)(char *old, char *new);
    int (*_lseek)(int file, int offset, int whence);
    int (*_open)(const char *name, int flags, int mode);
    int (*_read)(int file, char *ptr, int len);
    void *(*_sbrk)(int nbytes);
    int (*_stat)(char *file, struct stat *st);
    int (*_unlink)(char *name);
    int (*_wait)(int *status);
    int (*_write)(int file, char *buf, int nbytes);

    /* memory management */
    void *(*_malloc_region)(unsigned int nbytes, int loc);

    /* FreeRTOS interface */
};

/* memory regions */
#define GK_MALLOC_REGION_RAM                    0
#define GK_MALLOC_REGION_SDRAM                  1
#define GK_MALLOC_REGION_EITHER_PREFER_RAM      2
#define GK_MALLOC_REGION_EITHER_PREFER_SDRAM    3

/* filled in by ELF loader */
extern struct gk_syscalls *__gk_syscalls;

#ifdef __cplusplus
}
#endif

#endif

