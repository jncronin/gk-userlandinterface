#ifndef SYSCALLS_H
#define SYSCALLS_H

#ifndef _POSIX_READER_WRITER_LOCKS
#define _POSIX_READER_WRITER_LOCKS
#endif
#ifndef _UNIX98_THREAD_MUTEX_ATTRIBUTES
#define _UNIX98_THREAD_MUTEX_ATTRIBUTES
#endif

#include <sys/types.h>
#include <signal.h>
#include "_netinet_in.h"
#include "_gk_proccreate.h"
#include "_gk_gpu.h"

#define GK_TLS_POINTER_ADDRESS      0x30002000U
#define GK_CUR_MS_ADDRESS           0x30002010U
#define GK_TOFFSET_ADDRESS          0x30002020U

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
    __syscall_pthread_create,
    __syscall_proccreate,
    __syscall_pthread_setname_np,
    __syscall_pthread_sigmask,
    __syscall_get_thread_priority,
    __syscall_set_thread_priority,
    __syscall_pthread_mutex_init,
    __syscall_pthread_mutex_destroy,
    __syscall_pthread_mutex_trylock,
    __syscall_pthread_mutex_unlock,
    __syscall_pthread_join,
    __syscall_pthread_key_create,
    __syscall_pthread_key_delete,
    __syscall_pthread_getspecific,
    __syscall_pthread_setspecific,
    __syscall_sleep_ms,
    __syscall_clock_gettime,
    __syscall_pthread_cond_init,
    __syscall_pthread_cond_destroy,
    __syscall_pthread_cond_timedwait,
    __syscall_pthread_cond_signal,

    __syscall_memalloc,
    __syscall_memdealloc,
    __syscall_setprot,

    __syscall_gpuenqueue,

    __syscall_mkdir,
    __syscall_mkfifo,
    __syscall_rmdir,
    __syscall_chmod,

    __syscall_times,

    __syscall_peekevent,

    __syscall_ftruncate,

    __syscall_getscreenmode,

    __syscall_newlibinithook,

    __syscall_pthread_exit,

    __syscall_setwindowtitle,

    __syscall_cacheflush,
    __syscall_rewinddir,

    __syscall_pthread_rwlock_init,
    __syscall_pthread_rwlock_destroy,
    __syscall_pthread_rwlock_tryrdlock,
    __syscall_pthread_rwlock_trywrlock,
    __syscall_pthread_rwlock_unlock,

    __syscall_read_tp,

    __syscall_sem_init,
    __syscall_sem_destroy,
    __syscall_sem_trywait,
    __syscall_sem_post,
    __syscall_sem_getvalue,

    __syscall_thread_cleanup,

    __syscall_audiosetmode,
    __syscall_audioenable,
    __syscall_audioqueuebuffer,
    __syscall_audiowaitfree,

    __syscall_pthread_detach,
    __syscall_pthread_cancel,
    __syscall_getheap,

    __syscall_sched_get_priority_min,
    __syscall_sched_get_priority_max,

    __syscall_sleep_us,
    __syscall_get_env_count,
    __syscall_get_ienv_size,
    __syscall_get_ienv
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

#define CLOCK_WAIT_FOREVER      -1
#define CLOCK_TRY_ONCE          -2

struct __syscall_trywait_params
{
    void *sync;
    int clock_id;
    const struct timespec *until;
};

struct __syscall_proccreate_params
{
    const char *fname;
    const struct proccreate_t *proc_info;
    pid_t *pid;
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

struct __syscall_pthread_setname_np_params
{
    pthread_t thread;
    const char *name;
};

struct __syscall_pthread_sigmask_params
{
    int how;
    const sigset_t *set;
    sigset_t *old;
};

struct __syscall_set_thread_priority_params
{
    void *t;
    int priority;
};

struct __syscall_pthread_join_params
{
    void *t;
    void **retval;
};

struct __syscall_pthread_mutex_init_params
{
    pthread_mutex_t *mutex;
    const pthread_mutexattr_t *attr;
};

struct __syscall_pthread_rwlock_init_params
{

    pthread_rwlock_t *lock;
    const pthread_rwlockattr_t *attr;
};

struct __syscall_pthread_key_create_params
{
    pthread_key_t *key;
    void (*destructor)(void *);
};

struct __syscall_pthread_getspecific_params
{
    pthread_key_t key;
    void **retp;
};

struct __syscall_pthread_setspecific_params
{
    pthread_key_t key;
    const void *value;
};

struct __syscall_clock_gettime_params
{
    clockid_t clk_id;
    struct timespec *tp;
};

struct __syscall_pthread_cond_init_params
{
    pthread_cond_t *cond;
    const pthread_condattr_t *attr;
};

struct __syscall_pthread_cond_timedwait_params
{
    pthread_cond_t *cond;
    pthread_mutex_t *mutex;
    const struct timespec *abstime;
    int *signalled;
};

struct __syscall_memalloc_params
{
    size_t len;
    void **retaddr;
    int is_sync;
};

struct __syscall_memdealloc_params
{
    size_t len;
    const void *retaddr;
};

struct __syscall_setprot_params
{
    void *addr;
    int is_read, is_write, is_exec;
};

struct __syscall_gpuenqueue_params
{
    const struct gpu_message *msgs;
    size_t nmsg;
    size_t *nsent;
};

struct __syscall_mkdir_params
{
    const char *pathname;
    mode_t mode;
};

struct __syscall_times_params
{
    struct tms *buf;
    clock_t *retval;
};

struct __syscall_ftruncate_params
{
    int fd;
    off_t length;
};

struct __syscall_getscreenmode_params
{
    int *x, *y, *pf;
};

struct __syscall_readdir_params
{
    int fd;
    struct dirent *de;
};

struct __syscall_cacheflush_params
{
    void *addr;
    size_t len;
    int is_exec;
};

struct __syscall_sem_init_params
{
    void *sem;
    int pshared;
    unsigned int value;
};

struct __syscall_sem_getvalue_params
{
    void *sem;
    int *outval;
};

struct __syscall_audiosetmode_params
{
    int nchan;
    int nbits;
    int freq;
    size_t buf_size_bytes;
};

struct __syscall_audioqueuebuffer_params
{
    const void *buffer;
    void **next_buffer;
};

struct __syscall_get_ienv_params
{
    char *outbuf;
    size_t outbuf_size;
    unsigned int i;
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

#ifdef __cplusplus
}
#endif

#endif
