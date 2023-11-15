#include "zmalloc.h"
#include <stdlib.h>
#include <stddef.h>

static size_t used_memory = 0;

void *zmalloc(size_t size) {
	void *ptr = malloc(size + sizeof(size_t));
	*((size_t*)ptr) = size;
	used_memory += size + sizeof(size_t);
	return ptr + sizeof(size_t);
}

void zfree(void *ptr) {
	if (ptr == NULL) return;
	void *real_ptr = ptr - sizeof(size_t);
	size_t oldsize = *((size_t*)real_ptr);
	used_memory -= oldsize + sizeof(size_t);
	free(real_ptr);
}

size_t zmalloc_used_memory(void) {
	return used_memory;
}
