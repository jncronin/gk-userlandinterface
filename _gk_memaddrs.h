#ifndef __GK_MEMADDRS_H
#define __GK_MEMADDRS_H

#if __GAMEKID__ == 4
#define GK_PROCESS_INTERFACE_START  0x3ffe0000000ULL

#define GK_SCR_L1_B0                (GK_PROCESS_INTERFACE_START + 0)
#define GK_SCR_L1_B1                (GK_PROCESS_INTERFACE_START + 0x1000000ULL)
#define GK_SCR_L1_B2                (GK_PROCESS_INTERFACE_START + 0x2000000ULL)
#define GK_ROINFO_PAGE              (GK_PROCESS_INTERFACE_START + 0x3000000ULL)
#define GK_TIM3                     (GK_PROCESS_INTERFACE_START + 0x3010000ULL)
#define GK_KERNEL_INFO_PAGE         (GK_PROCESS_INTERFACE_START + 0x3020000ULL)

#define GK_CUR_S_ADDRESS            (GK_ROINFO_PAGE + 0xfe00ULL)
#define GK_TIM_PRECISION_NS_ADDRESS (GK_ROINFO_PAGE + 0xfe08ULL)
#define GK_TOFFSET_ADDRESS          (GK_ROINFO_PAGE + 0xfe10ULL)
#define GK_JOYSTICK_ADDRESS         (GK_ROINFO_PAGE + 0xfe80ULL)
#define GK_TILT_ADDRESS             (GK_ROINFO_PAGE + 0xff00ULL)

struct gk_kernel_info
{
    unsigned int gk_ver;
    unsigned int max_screen_width;
    unsigned int max_screen_height;
    unsigned int ncores;
    unsigned int page_size;
} __attribute__((packed));

#define GK_KERNEL_INFO ((const struct gk_kernel_info *)(GK_KERNEL_INFO_PAGE))

#else
#define GK_TLS_POINTER_ADDRESS      0x58004518U
#define GK_CUR_MS_ADDRESS           0x58004500U
#define GK_TOFFSET_ADDRESS          0x58004508U
#define GK_JOYSTICK_ADDRESS         0x5800451cU
#define GK_TILT_ADDRESS             0x58004530U
#endif

#endif
