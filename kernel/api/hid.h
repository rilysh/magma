/*
 *    __  __                      
 *   |  \/  |__ _ __ _ _ __  __ _ 
 *   | |\/| / _` / _` | '  \/ _` |
 *   |_|  |_\__,_\__, |_|_|_\__,_|
 *               |___/        
 * 
 *  Magma is a UNIX-like operating system that consists of a kernel written in C and
 *  i?86 assembly, and userland binaries written in C.
 *     
 *  Copyright (c) 2023 Nexuss, John Paul Wohlscheid, rilysh, Milton612, and FueledByCocaine
 * 
 *  This file may or may not contain code from https://github.com/mosmeh/yagura, and/or
 *  https://github.com/mit-pdos/xv6-public. Both projects have the same license as this
 *  project, and the license can be seen below:
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

enum {
    KEYCODE_NONE,
    KEYCODE_BACKSPACE,
    KEYCODE_DELETE,
    KEYCODE_TAB,
    KEYCODE_RETURN,
    KEYCODE_ESCAPE,
    KEYCODE_SPACE,
    KEYCODE_UP,
    KEYCODE_DOWN,
    KEYCODE_RIGHT,
    KEYCODE_LEFT,
    KEYCODE_INSERT,
    KEYCODE_HOME,
    KEYCODE_END,
    KEYCODE_PAGE_UP,
    KEYCODE_PAGE_DOWN,
    KEYCODE_F1,
    KEYCODE_F2,
    KEYCODE_F3,
    KEYCODE_F4,
    KEYCODE_F5,
    KEYCODE_F6,
    KEYCODE_F7,
    KEYCODE_F8,
    KEYCODE_F9,
    KEYCODE_F10,
    KEYCODE_F11,
    KEYCODE_F12,
    KEYCODE_0,
    KEYCODE_1,
    KEYCODE_2,
    KEYCODE_3,
    KEYCODE_4,
    KEYCODE_5,
    KEYCODE_6,
    KEYCODE_7,
    KEYCODE_8,
    KEYCODE_9,
    KEYCODE_EXCLAIM,
    KEYCODE_DOUBLE_QUOTE,
    KEYCODE_HASH,
    KEYCODE_DOLLAR,
    KEYCODE_PERCENT,
    KEYCODE_AMPERSAND,
    KEYCODE_QUOTE,
    KEYCODE_LEFT_PAREN,
    KEYCODE_RIGHT_PAREN,
    KEYCODE_ASTERISK,
    KEYCODE_PLUS,
    KEYCODE_COMMA,
    KEYCODE_MINUS,
    KEYCODE_PERIOD,
    KEYCODE_SLASH,
    KEYCODE_COLON,
    KEYCODE_SEMICOLON,
    KEYCODE_LESS,
    KEYCODE_EQUALS,
    KEYCODE_GREATER,
    KEYCODE_QUESTION,
    KEYCODE_AT,
    KEYCODE_LEFT_BRACKET,
    KEYCODE_BACKSLASH,
    KEYCODE_RIGHT_BRACKET,
    KEYCODE_CARET,
    KEYCODE_UNDERSCORE,
    KEYCODE_BACK_QUOTE,
    KEYCODE_A,
    KEYCODE_B,
    KEYCODE_C,
    KEYCODE_D,
    KEYCODE_E,
    KEYCODE_F,
    KEYCODE_G,
    KEYCODE_H,
    KEYCODE_I,
    KEYCODE_J,
    KEYCODE_K,
    KEYCODE_L,
    KEYCODE_M,
    KEYCODE_N,
    KEYCODE_O,
    KEYCODE_P,
    KEYCODE_Q,
    KEYCODE_R,
    KEYCODE_S,
    KEYCODE_T,
    KEYCODE_U,
    KEYCODE_V,
    KEYCODE_W,
    KEYCODE_X,
    KEYCODE_Y,
    KEYCODE_Z,
    KEYCODE_LEFT_CURLY_BRACKET,
    KEYCODE_PIPE,
    KEYCODE_RIGHT_CURLY_BRACKET,
    KEYCODE_TILDE,
    KEYCODE_NUMLOCK,
    KEYCODE_CAPS_LOCK,
    KEYCODE_SCROLL_LOCK,
    KEYCODE_RIGHT_SHIFT,
    KEYCODE_LEFT_SHIFT,
    KEYCODE_CONTROL,
    KEYCODE_ALT,
    KEYCODE_SUPER,
    KEYCODE_PRINT,
    KEYCODE_SYS_REQ,
    KEYCODE_MENU
};

#define KEY_MODIFIER_ALT 0x1
#define KEY_MODIFIER_CTRL 0x2
#define KEY_MODIFIER_SHIFT 0x4
#define KEY_MODIFIER_SUPER 0x8
#define KEY_MODIFIER_ALTGR 0x10

typedef struct key_event {
    uint16_t scancode;
    uint8_t modifiers;
    uint8_t keycode;
    char key;
    bool pressed;
} key_event;

#define MOUSE_BUTTON_LEFT 0x1
#define MOUSE_BUTTON_RIGHT 0x2
#define MOUSE_BUTTON_MIDDLE 0x4

typedef struct mouse_event {
    int16_t dx;
    int16_t dy;
    uint8_t buttons;
} mouse_event;
