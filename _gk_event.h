#ifndef _GK_EVENT_H
#define _GK_EVENT_H

struct Event
{
    enum event_type_t {
        KeyDown,
        KeyUp,
        MouseDown,
        MouseMove,
        MouseUp,
        ButtonDown,
        ButtonUp,
        AxisMotion,
        CaptionChange,
        RefreshScreen,
        SupervisorSetVisible,


        event_type_last = 2147483647  // force enum to 4 bytes
    } type;

    union
    {
        unsigned short int key;
        struct 
        {
            short int x, y;
            unsigned char is_rel;
            unsigned char buttons;
        } mouse_data;
        struct
        {
            short int axis;
            short int value;
        } axis_data;
        struct
        {
            short int visible;
            short int screen;
        } setvis_data;
    };
};



#endif
