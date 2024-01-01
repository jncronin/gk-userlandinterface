#ifndef GKSYSCALLS_H
#define GKSYSCALLS_H

#include <sys/stat.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct gk_syscalls
{
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
};

extern struct gk_syscalls *__gk_syscalls;

#ifdef __cplusplus
}
#endif

#endif

