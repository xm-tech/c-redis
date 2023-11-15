#ifndef __ZMALLOC_H__
#define __ZMALLOC_H__

#include <stddef.h>

void *zmalloc(size_t size);
void *zrealloc(void *ptr, size_t size);
void zfree(void *ptr);
char *zstrdup(const char *s);
size_t zmalloc_used_memory(void);

#endif
