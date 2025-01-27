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

#include "memory.h"
#include <common/extra.h>
#include <common/string.h>
#include <kernel/boot_defs.h>
#include <kernel/panic.h>
#include <kernel/system.h>

#define MAGIC 0x1d578e50

struct header {
    uint32_t magic;
    size_t size;
    unsigned char data[];
};

void* kaligned_alloc(size_t alignment, size_t size) {
    if (size == 0)
        return NULL;

    ASSERT(alignment <= PAGE_SIZE);

    size_t data_offset = round_up(sizeof(struct header), alignment);
    size_t real_size = data_offset + size;
    uintptr_t addr = range_allocator_alloc(&kernel_vaddr_allocator, real_size);
    if (IS_ERR(addr))
        return NULL;
    if (IS_ERR(paging_map_to_free_pages(addr, real_size, PAGE_WRITE | PAGE_GLOBAL)))
        return NULL;

    struct header* header = (struct header*)addr;
    header->magic = MAGIC;
    header->size = real_size;

    void* ptr = (void*)((uintptr_t)addr + data_offset);
    memset(ptr, 0, size);
    return ptr;
}

/* Returns a pointer to allocated memory with the size being the amount provided as the argument... */
void* kmalloc(size_t size) {
    return kaligned_alloc(alignof(max_align_t), size);
}

static struct header* header_from_ptr(void* ptr) {
    uintptr_t addr = round_down((uintptr_t)ptr, PAGE_SIZE);
    if ((uintptr_t)ptr - addr < sizeof(struct header))
        addr -= PAGE_SIZE;

    struct header* header = (struct header*)addr;
    ASSERT(header->magic == MAGIC);
    return header;
}

void* krealloc(void* ptr, size_t new_size) {
    if (!ptr)
        return kmalloc(new_size);
    if (new_size == 0) {
        kfree(ptr);
        return NULL;
    }

    struct header* old_header = header_from_ptr(ptr);

    void* new_ptr = kmalloc(new_size);
    if (!new_ptr)
        return NULL;
    struct header* new_header = header_from_ptr(new_ptr);

    memcpy(new_header, old_header, old_header->size);
    kfree(ptr);

    return new_ptr;
}

/* Free the memory by giving a pointer to the address given to you by the function that allocated the memory... */
void kfree(void* ptr) {
    if (!ptr)
        return;
    struct header* header = header_from_ptr(ptr);
    size_t size = header->size;
    paging_unmap((uintptr_t)header, size);
    ASSERT_OK(range_allocator_free(&kernel_vaddr_allocator, (uintptr_t)header, size));
}

char* kstrdup(const char* src) {
    size_t len = strlen(src);
    char* buf = kmalloc((len + 1) * sizeof(char));
    if (!buf)
        return NULL;

    memcpy(buf, src, len);
    buf[len] = '\0';
    return buf;
}

char* kstrndup(const char* src, size_t n) {
    size_t len = strnlen(src, n);
    char* buf = kmalloc((len + 1) * sizeof(char));
    if (!buf)
        return NULL;

    memcpy(buf, src, len);
    buf[len] = '\0';
    return buf;
}
