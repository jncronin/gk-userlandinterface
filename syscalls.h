#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <sys/types.h>
#include "_netinet_in.h"

enum syscall_no
{
    StartFirstThread = 0,
    GetThreadHandle = 1,

    FlipFrameBuffer,
    SetFrameBuffer,
    GetFrameBuffer,

    /* IPC functions */
    WaitSimpleSignal,

    /* newlib libgloss */
    __syscall_close1,
    __syscall_execve,
    __syscall_exit,
    __syscall_fork,
    __syscall_fstat,
    __syscall_getpid,
    __syscall_gettimeofday,
    __syscall_isatty,
    __syscall_kill,
    __syscall_link,
    __syscall_lseek,
    __syscall_open,
    __syscall_read,
    __syscall_sbrk,
    __syscall_stat,
    __syscall_unlink,
    __syscall_wait,
    __syscall_write,

    /* extra non-newlib gk functions */
    __syscall_waitpid,
    __syscall_dup,
    __syscall_chdir,
    __syscall_fchdir,
    __syscall_getcwd,
    __syscall_pipe,
    __syscall_opendir,
    __syscall_closedir,
    __syscall_readdir,
    __syscall_lstat,
    __syscall_socket,
    __syscall_bind,
    __syscall_accept,
    __syscall_listen,
    __syscall_connect,

    __syscall_close2,
    __syscall_sendto,
    __syscall_recvfrom,
    __syscall_pthread_create
};

/* parameters for above */
struct WaitSimpleSignal_params
{
    union
    {
        int32_t ival1;
        uint32_t uval1;
        void *pval1;
    };
    union
    {
        int32_t ival2;
        uint32_t uval2;
        void *pval2;
    };
};

struct __syscall_pthread_create_params
{
    pthread_t *thread;
    const pthread_attr_t *attr;
    void *(*start_routine)(void *);
    void *arg;
};

struct __syscall_socket_params
{
    int domain;
    int type;
    int protocol;
};

struct __syscall_bind_params
{
    int sockfd;
    const struct sockaddr *addr;
    socklen_t addrlen;
};

struct __syscall_listen_params
{
    int sockfd;
    int backlog;
};

struct __syscall_accept_params
{
    int sockfd;
    struct sockaddr *addr;
    socklen_t *addrlen;
};

struct __syscall_sendto_params
{
    int sockfd;
    const void *buf;
    size_t len;
    int flags;
    const struct sockaddr *dest_addr;
    socklen_t addrlen;
};

struct __syscall_recvfrom_params
{
    int sockfd;
    void *buf;
    size_t len;
    int flags;
    struct sockaddr *src_addr;
    socklen_t *addrlen;
};

struct __syscall_execve_params
{
    char *name;
	char **argv;
	char **env;
};

struct __syscall_fstat_params
{
    int fd;
    struct stat *buf;
};

struct __syscall_gettimeofday_params
{
    struct timeval *tv;
    void *tz;
};

struct __syscall_kill_params
{
    pid_t pid;
    int sig;
};

struct __syscall_stat_params
{
    const char *pathname;
    struct stat *st;
};

struct __syscall_link_params
{
    const char *oldpath;
    const char *newpath;
};

struct __syscall_lseek_params
{
    int file;
    int offset;
    int whence;
};

struct __syscall_open_params
{
    const char *name;
    int flags;
    int mode;
};

struct __syscall_read_params
{
    int file;
    char *ptr;
    int len;
};

struct __syscall_waitpid_params
{
    pid_t pid;
    int *stat_loc;
    int options;
};

enum syscall_framebuffer_pixelformat
{
    ARGB8888 = 0,
    RGB888 = 1,
    RGB565 = 2,
    ARGB1555 = 3,
    ARGB4444 = 4,
    L8 = 5,
    AL44 = 6,
    AL88 = 7
};

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

static inline void __syscall(enum syscall_no sno, void *r1, void *r2, void *r3)
{
    register unsigned int _sno asm("r0") = sno;
    register void *_r1 asm("r1") = r1;
    register void *_r2 asm("r2") = r2;
    register void *_r3 asm("r3") = r3;
    __asm volatile
    (
        "svc #0                 \n"
        :: "r"(_sno), "r"(_r1), "r"(_r2), "r"(_r3) : "memory"
    );
}

static inline void *__syscall_GetThreadHandle()
{
    void *ret = NULL;
    __syscall(GetThreadHandle, &ret, NULL, NULL);
    return ret;
}

static inline void *__syscall_FlipFrameBuffer()
{
    void *ret = NULL;
    __syscall(FlipFrameBuffer, &ret, NULL, NULL);
    return ret;
}

static inline void *__syscall_GetFrameBuffer()
{
    void *ret = NULL;
    __syscall(GetFrameBuffer, &ret, NULL, NULL);
    return ret;
}

static inline void __syscall_SetFrameBuffer(void *b0, void *b1, enum syscall_framebuffer_pixelformat pf)
{
    __syscall(SetFrameBuffer, b0, b1, (void*)pf);
}

#ifdef __cplusplus
}
#endif

#endif
