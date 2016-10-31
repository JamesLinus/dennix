/* Copyright (c) 2016, Dennis Wölfing
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* kernel/include/dennix/kernel/terminal.h
 * Terminal class.
 */

#ifndef KERNEL_TERMINAL_H
#define KERNEL_TERMINAL_H

#include <dennix/termios.h>
#include <dennix/kernel/keyboard.h>
#include <dennix/kernel/vnode.h>

#define TERMINAL_BUFFER_SIZE 4096

class TerminalBuffer {
public:
    TerminalBuffer();
    size_t available();
    bool backspace();
    char read();
    void reset();
    void write(char c, bool canonicalMode);
private:
    char circularBuffer[TERMINAL_BUFFER_SIZE];
    volatile size_t readIndex;
    volatile size_t lineIndex;
    volatile size_t writeIndex;
};

class Terminal : public Vnode, public KeyboardListener {
public:
    Terminal();
    virtual ssize_t read(void* buffer, size_t size);
    virtual int tcgetattr(struct termios* result);
    virtual int tcsetattr(int flags, const struct termios* termios);
    virtual ssize_t write(const void* buffer, size_t size);
private:
    virtual void onKeyboardEvent(int key);
private:
    TerminalBuffer terminalBuffer;
    struct termios termio;
};

extern Terminal terminal;

#endif
