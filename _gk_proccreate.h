#ifndef __GK_PROCCREATE_H
#define __GK_PROCCREATE_H

#if __GAMEKID__ >= 4
#define GK_MAX_OPEN_FILES      256
#else
#define GK_MAX_OPEN_FILES       16
#endif

#define GK_KEYLEFT              0
#define GK_KEYRIGHT             1
#define GK_KEYUP                2
#define GK_KEYDOWN              3
#define GK_KEYA                 4
#define GK_KEYB                 5
#define GK_KEYX                 6
#define GK_KEYY                 7
#define GK_KEYVOLDOWN           8
#define GK_KEYVOLUP             9
#define GK_KEYTILTLEFT          10
#define GK_KEYTILTRIGHT         11
#define GK_KEYTILTUP            12
#define GK_KEYTILTDOWN          13
#define GK_KEYMENU              14
#define GK_KEYPOWER             15
#define GK_KEYJOY               16
#define GK_KEYJOYDIGILEFT       17
#define GK_KEYJOYDIGIRIGHT      18
#define GK_KEYJOYDIGIUP         19
#define GK_KEYJOYDIGIDOWN       20
#define GK_KEYLB                21
#define GK_KEYRB                22
#define GK_KEYJOYB              23
#define GK_KEYJOYBDIGILEFT      24
#define GK_KEYJOYBDIGIRIGHT     25
#define GK_KEYJOYBDIGIUP        26
#define GK_KEYJOYBDIGIDOWN      27
#define GK_KEYLT                28
#define GK_KEYRT                29

#define GK_NUMKEYS              30

struct prockeymap_t
{
    char gamepad_is_keyboard;
    char gamepad_is_mouse;
    char gamepad_is_joystick;
    char tilt_is_keyboard;
    char tilt_is_joystick;
    char joystick_is_joystick;
    char touch_is_mouse;
    char joystick_is_mouse;
    unsigned short int gamepad_to_scancode[GK_NUMKEYS];
};

#define STACK_PREFERENCE_TCM_RAM_SDRAM      0
#define STACK_PREFERENCE_SDRAM_RAM_TCM      1

struct proccreate_t
{
    int acquire_fds[GK_MAX_OPEN_FILES];
    uint32_t heap_size;
    unsigned int core_mask;
    unsigned int prefer_core_mask;
    unsigned int with_focus;
    unsigned int pixel_format;
    int argc;
    const char **argv;
    uint32_t stack_size;
    int is_priv;
    int heap_is_exec;
    const char *cwd;
    unsigned short screen_w, screen_h;
    int screen_ignore_vsync;

    struct prockeymap_t keymap;

    unsigned int stack_preference;

    uint32_t graphics_texture_size;
    const char *osd;
    int screen_overwritten_each_frame;

    int audio_max_buffer_size;
    unsigned int screen_refresh;
};

#endif
