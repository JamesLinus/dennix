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

/* kernel/include/dennix/stat.h
 * File information.
 */

#ifndef _DENNIX_STAT_H
#define _DENNIX_STAT_H

#include <dennix/types.h>

#define S_IFBLK 010000
#define S_IFCHR 020000
#define S_IFIFO 030000
#define S_IFREG 040000
#define S_IFDIR 050000
#define S_IFLNK 060000
#define S_IFSOCK 070000

#define S_IFMT 070000

struct stat {
    /* TODO: Add the other members of struct stat */
    __mode_t st_mode;
};

#endif
