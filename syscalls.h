#ifndef SYSCALLS_H
#define SYSCALLS_H

enum syscall_no
{
    StartFirstThread = 0,
    GetThreadHandle = 1,

    FlipFrameBuffer,
    SetFrameBuffer
};

#endif
