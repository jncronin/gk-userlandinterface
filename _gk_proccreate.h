#ifndef __GK_PROCCREATE_H
#define __GK_PROCCREATE_H

#define GK_MAX_OPEN_FILES      16

#define GK_NUMKEYS              8

#define GK_KEYLEFT              0
#define GK_KEYRIGHT             1
#define GK_KEYUP                2
#define GK_KEYDOWN              3
#define GK_KEYA                 4
#define GK_KEYB                 5
#define GK_KEYX                 6
#define GK_KEYY                 7

struct prockeymap_t
{
    char gamepad_is_keyboard;
    char gamepad_is_mouse;
    char gamepad_is_joystick;
    unsigned short int gamepad_to_scancode[GK_NUMKEYS];
};

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
};

#endif
