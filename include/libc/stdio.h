#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

#include <stddef.h>

typedef struct FILE FILE;

size_t fread(void *, size_t, size_t, FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);

#endif
