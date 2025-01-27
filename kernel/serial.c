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

#include "serial.h"
#include "console/console.h"
#include "interrupts.h"
#include "panic.h"

static void init_port(uint16_t port) {
    out8(port + 1, 0x00);
    out8(port + 3, 0x80);
    out8(port + 0, 0x03);
    out8(port + 1, 0x00);
    out8(port + 3, 0x03);
    out8(port + 2, 0xc7);
    out8(port + 4, 0x0b);
}

void serial_init(void) { init_port(SERIAL_COM1); }

#define DATA_READY 0x1
#define TRANSMITTER_HOLDING_REGISTER_EMPTY 0x20

static bool read_and_report(uint16_t port) {
    uint8_t status = in8(port + 5);
    if (status != 0xff && (status & 1)) {
        serial_console_on_char(port, in8(port));
        return true;
    }
    return false;
}

static void handle_1_and_3(registers* regs) {
    (void)regs;
    while (read_and_report(SERIAL_COM1) || read_and_report(SERIAL_COM3))
        ;
}

static void handle_2_and_4(registers* regs) {
    (void)regs;
    while (read_and_report(SERIAL_COM2) || read_and_report(SERIAL_COM4))
        ;
}

bool serial_enable_port(uint16_t port) {
    if (!serial_is_valid_port(port))
        return false;

    init_port(port);

    out8(port + 4, 0x1e);
    out8(port + 0, 0xae);

    if (in8(port + 0) != 0xae)
        return false;

    out8(port + 4, 0x0f);
    out8(port + 1, 0x01);

    switch (port) {
    case SERIAL_COM1:
    case SERIAL_COM3:
        idt_register_interrupt_handler(IRQ(4), handle_1_and_3);
        return true;
    case SERIAL_COM2:
    case SERIAL_COM4:
        idt_register_interrupt_handler(IRQ(3), handle_2_and_4);
        return true;
    }
    UNREACHABLE();
}

static void write_char(uint16_t port, char c) {
    while (!(in8(port + 5) & TRANSMITTER_HOLDING_REGISTER_EMPTY))
        ;
    out8(port, c);
}

size_t serial_write(uint16_t port, const char* s, size_t count) {
    // this function is also called by kprintf, which can be used in critical
    // situations, so we protect it by disabling interrupts, not with mutex.
    bool int_flag = push_cli();

    for (size_t i = 0; i < count; ++i) {
        if (s[i] == '\n')
            write_char(port, '\r');
        write_char(port, s[i]);
    }

    pop_cli(int_flag);
    return count;
}
