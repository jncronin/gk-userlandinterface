#ifndef _GK_EVENT_H
#define _GK_EVENT_H

struct Event
{
    enum event_type_t {
        KeyDown,
        KeyUp,
        MouseDown,
        MouseDrag,
        MouseUp,
        ButtonDown,
        ButtonUp,
        AxisMotion
    };

    event_type_t type;

    union
    {
        unsigned short int key;
        struct 
        {
            unsigned short int x, y;
        } mouse_data;
        struct
        {
            short int axis;
            short int value;
        } axis_data;
    };
};



#endif
