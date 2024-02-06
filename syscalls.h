#ifndef SYSCALLS_H
#define SYSCALLS_H

enum syscall_no
{
    StartFirstThread = 0,
    GetThreadHandle = 1,

    FlipFrameBuffer,
    SetFrameBuffer,
    GetFrameBuffer,

    /* newlib libgloss */
    __syscall_close,
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
    __syscall_write
};

/* parameters for above */
struct __syscall_execve_params
{
    char *name;
	char **argv;
	char **env;
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
