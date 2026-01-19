/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_scancode.h
 *
 *  Defines keyboard scancodes.
 */

// Modified for GK

#include "_gk_proccreate.h"

#ifndef __gk_scancode_h_
#define __gk_scancode_h_

//#include "SDL_stdinc.h"

/**
 *  \brief The SDL keyboard scancode representation.
 *
 *  Values of this type are used to represent keyboard keys, among other places
 *  in the \link SDL_Keysym::scancode key.keysym.scancode \endlink field of the
 *  SDL_Event structure.
 *
 *  The values in this enumeration are based on the USB usage page standard:
 *  https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
 */
typedef enum
{
    GK_SCANCODE_UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    GK_SCANCODE_A = 4,
    GK_SCANCODE_B = 5,
    GK_SCANCODE_C = 6,
    GK_SCANCODE_D = 7,
    GK_SCANCODE_E = 8,
    GK_SCANCODE_F = 9,
    GK_SCANCODE_G = 10,
    GK_SCANCODE_H = 11,
    GK_SCANCODE_I = 12,
    GK_SCANCODE_J = 13,
    GK_SCANCODE_K = 14,
    GK_SCANCODE_L = 15,
    GK_SCANCODE_M = 16,
    GK_SCANCODE_N = 17,
    GK_SCANCODE_O = 18,
    GK_SCANCODE_P = 19,
    GK_SCANCODE_Q = 20,
    GK_SCANCODE_R = 21,
    GK_SCANCODE_S = 22,
    GK_SCANCODE_T = 23,
    GK_SCANCODE_U = 24,
    GK_SCANCODE_V = 25,
    GK_SCANCODE_W = 26,
    GK_SCANCODE_X = 27,
    GK_SCANCODE_Y = 28,
    GK_SCANCODE_Z = 29,

    GK_SCANCODE_1 = 30,
    GK_SCANCODE_2 = 31,
    GK_SCANCODE_3 = 32,
    GK_SCANCODE_4 = 33,
    GK_SCANCODE_5 = 34,
    GK_SCANCODE_6 = 35,
    GK_SCANCODE_7 = 36,
    GK_SCANCODE_8 = 37,
    GK_SCANCODE_9 = 38,
    GK_SCANCODE_0 = 39,

    GK_SCANCODE_RETURN = 40,
    GK_SCANCODE_ESCAPE = 41,
    GK_SCANCODE_BACKSPACE = 42,
    GK_SCANCODE_TAB = 43,
    GK_SCANCODE_SPACE = 44,

    GK_SCANCODE_MINUS = 45,
    GK_SCANCODE_EQUALS = 46,
    GK_SCANCODE_LEFTBRACKET = 47,
    GK_SCANCODE_RIGHTBRACKET = 48,
    GK_SCANCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    GK_SCANCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate GK_SCANCODE_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    GK_SCANCODE_SEMICOLON = 51,
    GK_SCANCODE_APOSTROPHE = 52,
    GK_SCANCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    GK_SCANCODE_COMMA = 54,
    GK_SCANCODE_PERIOD = 55,
    GK_SCANCODE_SLASH = 56,

    GK_SCANCODE_CAPSLOCK = 57,

    GK_SCANCODE_F1 = 58,
    GK_SCANCODE_F2 = 59,
    GK_SCANCODE_F3 = 60,
    GK_SCANCODE_F4 = 61,
    GK_SCANCODE_F5 = 62,
    GK_SCANCODE_F6 = 63,
    GK_SCANCODE_F7 = 64,
    GK_SCANCODE_F8 = 65,
    GK_SCANCODE_F9 = 66,
    GK_SCANCODE_F10 = 67,
    GK_SCANCODE_F11 = 68,
    GK_SCANCODE_F12 = 69,

    GK_SCANCODE_PRINTSCREEN = 70,
    GK_SCANCODE_SCROLLLOCK = 71,
    GK_SCANCODE_PAUSE = 72,
    GK_SCANCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    GK_SCANCODE_HOME = 74,
    GK_SCANCODE_PAGEUP = 75,
    GK_SCANCODE_DELETE = 76,
    GK_SCANCODE_END = 77,
    GK_SCANCODE_PAGEDOWN = 78,
    GK_SCANCODE_RIGHT = 79,
    GK_SCANCODE_LEFT = 80,
    GK_SCANCODE_DOWN = 81,
    GK_SCANCODE_UP = 82,

    GK_SCANCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    GK_SCANCODE_KP_DIVIDE = 84,
    GK_SCANCODE_KP_MULTIPLY = 85,
    GK_SCANCODE_KP_MINUS = 86,
    GK_SCANCODE_KP_PLUS = 87,
    GK_SCANCODE_KP_ENTER = 88,
    GK_SCANCODE_KP_1 = 89,
    GK_SCANCODE_KP_2 = 90,
    GK_SCANCODE_KP_3 = 91,
    GK_SCANCODE_KP_4 = 92,
    GK_SCANCODE_KP_5 = 93,
    GK_SCANCODE_KP_6 = 94,
    GK_SCANCODE_KP_7 = 95,
    GK_SCANCODE_KP_8 = 96,
    GK_SCANCODE_KP_9 = 97,
    GK_SCANCODE_KP_0 = 98,
    GK_SCANCODE_KP_PERIOD = 99,

    GK_SCANCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    GK_SCANCODE_APPLICATION = 101, /**< windows contextual menu, compose */
    GK_SCANCODE_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    GK_SCANCODE_KP_EQUALS = 103,
    GK_SCANCODE_F13 = 104,
    GK_SCANCODE_F14 = 105,
    GK_SCANCODE_F15 = 106,
    GK_SCANCODE_F16 = 107,
    GK_SCANCODE_F17 = 108,
    GK_SCANCODE_F18 = 109,
    GK_SCANCODE_F19 = 110,
    GK_SCANCODE_F20 = 111,
    GK_SCANCODE_F21 = 112,
    GK_SCANCODE_F22 = 113,
    GK_SCANCODE_F23 = 114,
    GK_SCANCODE_F24 = 115,
    GK_SCANCODE_EXECUTE = 116,
    GK_SCANCODE_HELP = 117,    /**< AL Integrated Help Center */
    GK_SCANCODE_MENU = 118,    /**< Menu (show menu) */
    GK_SCANCODE_SELECT = 119,
    GK_SCANCODE_STOP = 120,    /**< AC Stop */
    GK_SCANCODE_AGAIN = 121,   /**< AC Redo/Repeat */
    GK_SCANCODE_UNDO = 122,    /**< AC Undo */
    GK_SCANCODE_CUT = 123,     /**< AC Cut */
    GK_SCANCODE_COPY = 124,    /**< AC Copy */
    GK_SCANCODE_PASTE = 125,   /**< AC Paste */
    GK_SCANCODE_FIND = 126,    /**< AC Find */
    GK_SCANCODE_MUTE = 127,
    GK_SCANCODE_VOLUMEUP = 128,
    GK_SCANCODE_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     GK_SCANCODE_LOCKINGCAPSLOCK = 130,  */
/*     GK_SCANCODE_LOCKINGNUMLOCK = 131, */
/*     GK_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    GK_SCANCODE_KP_COMMA = 133,
    GK_SCANCODE_KP_EQUALSAS400 = 134,

    GK_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    GK_SCANCODE_INTERNATIONAL2 = 136,
    GK_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
    GK_SCANCODE_INTERNATIONAL4 = 138,
    GK_SCANCODE_INTERNATIONAL5 = 139,
    GK_SCANCODE_INTERNATIONAL6 = 140,
    GK_SCANCODE_INTERNATIONAL7 = 141,
    GK_SCANCODE_INTERNATIONAL8 = 142,
    GK_SCANCODE_INTERNATIONAL9 = 143,
    GK_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
    GK_SCANCODE_LANG2 = 145, /**< Hanja conversion */
    GK_SCANCODE_LANG3 = 146, /**< Katakana */
    GK_SCANCODE_LANG4 = 147, /**< Hiragana */
    GK_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    GK_SCANCODE_LANG6 = 149, /**< reserved */
    GK_SCANCODE_LANG7 = 150, /**< reserved */
    GK_SCANCODE_LANG8 = 151, /**< reserved */
    GK_SCANCODE_LANG9 = 152, /**< reserved */

    GK_SCANCODE_ALTERASE = 153,    /**< Erase-Eaze */
    GK_SCANCODE_SYSREQ = 154,
    GK_SCANCODE_CANCEL = 155,      /**< AC Cancel */
    GK_SCANCODE_CLEAR = 156,
    GK_SCANCODE_PRIOR = 157,
    GK_SCANCODE_RETURN2 = 158,
    GK_SCANCODE_SEPARATOR = 159,
    GK_SCANCODE_OUT = 160,
    GK_SCANCODE_OPER = 161,
    GK_SCANCODE_CLEARAGAIN = 162,
    GK_SCANCODE_CRSEL = 163,
    GK_SCANCODE_EXSEL = 164,

    GK_SCANCODE_KP_00 = 176,
    GK_SCANCODE_KP_000 = 177,
    GK_SCANCODE_THOUSANDSSEPARATOR = 178,
    GK_SCANCODE_DECIMALSEPARATOR = 179,
    GK_SCANCODE_CURRENCYUNIT = 180,
    GK_SCANCODE_CURRENCYSUBUNIT = 181,
    GK_SCANCODE_KP_LEFTPAREN = 182,
    GK_SCANCODE_KP_RIGHTPAREN = 183,
    GK_SCANCODE_KP_LEFTBRACE = 184,
    GK_SCANCODE_KP_RIGHTBRACE = 185,
    GK_SCANCODE_KP_TAB = 186,
    GK_SCANCODE_KP_BACKSPACE = 187,
    GK_SCANCODE_KP_A = 188,
    GK_SCANCODE_KP_B = 189,
    GK_SCANCODE_KP_C = 190,
    GK_SCANCODE_KP_D = 191,
    GK_SCANCODE_KP_E = 192,
    GK_SCANCODE_KP_F = 193,
    GK_SCANCODE_KP_XOR = 194,
    GK_SCANCODE_KP_POWER = 195,
    GK_SCANCODE_KP_PERCENT = 196,
    GK_SCANCODE_KP_LESS = 197,
    GK_SCANCODE_KP_GREATER = 198,
    GK_SCANCODE_KP_AMPERSAND = 199,
    GK_SCANCODE_KP_DBLAMPERSAND = 200,
    GK_SCANCODE_KP_VERTICALBAR = 201,
    GK_SCANCODE_KP_DBLVERTICALBAR = 202,
    GK_SCANCODE_KP_COLON = 203,
    GK_SCANCODE_KP_HASH = 204,
    GK_SCANCODE_KP_SPACE = 205,
    GK_SCANCODE_KP_AT = 206,
    GK_SCANCODE_KP_EXCLAM = 207,
    GK_SCANCODE_KP_MEMSTORE = 208,
    GK_SCANCODE_KP_MEMRECALL = 209,
    GK_SCANCODE_KP_MEMCLEAR = 210,
    GK_SCANCODE_KP_MEMADD = 211,
    GK_SCANCODE_KP_MEMSUBTRACT = 212,
    GK_SCANCODE_KP_MEMMULTIPLY = 213,
    GK_SCANCODE_KP_MEMDIVIDE = 214,
    GK_SCANCODE_KP_PLUSMINUS = 215,
    GK_SCANCODE_KP_CLEAR = 216,
    GK_SCANCODE_KP_CLEARENTRY = 217,
    GK_SCANCODE_KP_BINARY = 218,
    GK_SCANCODE_KP_OCTAL = 219,
    GK_SCANCODE_KP_DECIMAL = 220,
    GK_SCANCODE_KP_HEXADECIMAL = 221,

    GK_SCANCODE_LCTRL = 224,
    GK_SCANCODE_LSHIFT = 225,
    GK_SCANCODE_LALT = 226, /**< alt, option */
    GK_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
    GK_SCANCODE_RCTRL = 228,
    GK_SCANCODE_RSHIFT = 229,
    GK_SCANCODE_RALT = 230, /**< alt gr, option */
    GK_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

    GK_SCANCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     *  See https://usb.org/sites/default/files/hut1_2.pdf
     *
     *  There are way more keys in the spec than we can represent in the
     *  current scancode range, so pick the ones that commonly come up in
     *  real world usage.
     */
    /* @{ */

    GK_SCANCODE_AUDIONEXT = 258,
    GK_SCANCODE_AUDIOPREV = 259,
    GK_SCANCODE_AUDIOSTOP = 260,
    GK_SCANCODE_AUDIOPLAY = 261,
    GK_SCANCODE_AUDIOMUTE = 262,
    GK_SCANCODE_MEDIASELECT = 263,
    GK_SCANCODE_WWW = 264,             /**< AL Internet Browser */
    GK_SCANCODE_MAIL = 265,
    GK_SCANCODE_CALCULATOR = 266,      /**< AL Calculator */
    GK_SCANCODE_COMPUTER = 267,
    GK_SCANCODE_AC_SEARCH = 268,       /**< AC Search */
    GK_SCANCODE_AC_HOME = 269,         /**< AC Home */
    GK_SCANCODE_AC_BACK = 270,         /**< AC Back */
    GK_SCANCODE_AC_FORWARD = 271,      /**< AC Forward */
    GK_SCANCODE_AC_STOP = 272,         /**< AC Stop */
    GK_SCANCODE_AC_REFRESH = 273,      /**< AC Refresh */
    GK_SCANCODE_AC_BOOKMARKS = 274,    /**< AC Bookmarks */

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    GK_SCANCODE_BRIGHTNESSDOWN = 275,
    GK_SCANCODE_BRIGHTNESSUP = 276,
    GK_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    GK_SCANCODE_KBDILLUMTOGGLE = 278,
    GK_SCANCODE_KBDILLUMDOWN = 279,
    GK_SCANCODE_KBDILLUMUP = 280,
    GK_SCANCODE_EJECT = 281,
    GK_SCANCODE_SLEEP = 282,           /**< SC System Sleep */

    GK_SCANCODE_APP1 = 283,
    GK_SCANCODE_APP2 = 284,

    /* @} *//* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    GK_SCANCODE_AUDIOREWIND = 285,
    GK_SCANCODE_AUDIOFASTFORWARD = 286,

    /* @} *//* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
    /* @{ */

    GK_SCANCODE_SOFTLEFT = 287, /**< Usually situated below the display on phones and
                                      used as a multi-function feature key for selecting
                                      a software defined function shown on the bottom left
                                      of the display. */
    GK_SCANCODE_SOFTRIGHT = 288, /**< Usually situated below the display on phones and
                                       used as a multi-function feature key for selecting
                                       a software defined function shown on the bottom right
                                       of the display. */
    GK_SCANCODE_CALL = 289, /**< Used for accepting phone calls. */
    GK_SCANCODE_ENDCALL = 290, /**< Used for rejecting phone calls. */

    /* @} *//* Mobile keys */

    /* Add any other keys here. */

    GK_MOUSE_BUTTON = 300,
    GK_MOUSE_END = 399,

    GK_GAMEPAD_BUTTON = 400,
    GK_GAMEPAD_END = 499,

    GK_NUM_SCANCODES = 512, /**< not a key, just marks the number of scancodes
                                 for array bounds */

    GK_MODIFIER_SHIFT = 1024,
    GK_MODIFIER_CTRL = 2048,
    GK_MODIFIER_ALT = 4096,

    gk_scancode_last = 2147483647  // force enum to 4 bytes
} GK_Scancode;

#endif /* GK_SCANCODE_h_ */

/* vi: set ts=4 sw=4 expandtab: */
