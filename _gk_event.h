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
        CaptionChange
    };

    enum event_type_t type;

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
    };
};



#endif
