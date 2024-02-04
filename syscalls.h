#ifndef SYSCALLS_H
#define SYSCALLS_H

enum syscall_no
{
    StartFirstThread = 0,
    GetThreadHandle = 1,

    FlipFrameBuffer,
    SetFrameBuffer,
    GetFrameBuffer
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

static inline void __syscall(syscall_no sno, void *r1, void *r2, void *r3)
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

static inline void __syscall_SetFrameBuffer(void *b0, void *b1, syscall_framebuffer_pixelformat pf)
{
    __syscall(SetFrameBuffer, b0, b1, (void*)pf);
}

#ifdef __cplusplus
}
#endif

#endif
