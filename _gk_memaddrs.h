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
#define GK_CM33_USERSPACE_PAGE      (GK_PROCESS_INTERFACE_START + 0x3030000ULL)

#define GK_CUR_S_ADDRESS            (GK_ROINFO_PAGE + 0xfe00ULL)
#define GK_TIM_PRECISION_NS_ADDRESS (GK_ROINFO_PAGE + 0xfe08ULL)
#define GK_TOFFSET_ADDRESS          (GK_ROINFO_PAGE + 0xfe10ULL)

#define GK_KEYSTATE_ADDRESS         (GK_CM33_USERSPACE_PAGE + 0)
#define GK_JOYSTICK_ADDRESS         (GK_CM33_USERSPACE_PAGE + 4)
#define GK_JOYSTICKB_ADDRESS        (GK_CM33_USERSPACE_PAGE + 12)
#define GK_TILT_ADDRESS             (GK_CM33_USERSPACE_PAGE + 20)
#define GK_JOYSTICK_RAW_ADDRESS     (GK_CM33_USERSPACE_PAGE + 64)
#define GK_JOYSTICKB_RAW_ADDRESS    (GK_CM33_USERSPACE_PAGE + 72)

#define GK_HEAP_START               0x3ffc0000000ULL
#define GK_STACKS_START             0x3ffa0000000ULL

#include <stdint.h>

struct gk_kernel_info
{
    unsigned int gk_ver;
    unsigned int max_screen_width;
    unsigned int max_screen_height;
    unsigned int ncores;
    unsigned int page_size;

    uint64_t joystick_buttons;
    unsigned int joystick_nbuttons;
    unsigned int joystick_naxes;
    int16_t *joystick_axes[6];
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
