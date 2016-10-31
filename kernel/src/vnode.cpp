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

/* kernel/src/vnode.cpp
 * Vnode class.
 */

#include <errno.h>
#include <dennix/kernel/vnode.h>

Vnode::Vnode(mode_t mode) {
    this->mode = mode;
}

// Default implementation. Inheriting classes will override these functions.
bool Vnode::isSeekable() {
    return false;
}

Vnode* Vnode::openat(const char* /*path*/, int /*flags*/, mode_t /*mode*/) {
    errno = ENOTDIR;
    return nullptr;
}

ssize_t Vnode::pread(void* /*buffer*/, size_t /*size*/, off_t /*offset*/) {
    errno = EBADF;
    return -1;
}

ssize_t Vnode::read(void* /*buffer*/, size_t /*size*/) {
    errno = EBADF;
    return -1;
}

ssize_t Vnode::readdir(unsigned long /*offset*/, void* /*buffer*/,
        size_t /*size*/) {
    errno = EBADF;
    return -1;
}

int Vnode::tcgetattr(struct termios* /*result*/) {
    errno = ENOTTY;
    return -1;
}

int Vnode::tcsetattr(int /*flags*/, const struct termios* /*termio*/) {
    errno = ENOTTY;
    return -1;
}

int Vnode::stat(struct stat* result) {
    result->st_mode = mode;
    return 0;
}

ssize_t Vnode::write(const void* /*buffer*/, size_t /*size*/) {
    errno = EBADF;
    return -1;
}
