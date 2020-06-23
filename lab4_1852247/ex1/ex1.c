#include "ex1.h"
#include <stdlib.h>

void * aligned_malloc(unsigned int size, unsigned int align) {
    void *p;

    if(size == 0 || align <= 0)
        return NULL;
	
	p = (void *)malloc(size + align + sizeof(size_t));

    if(p == NULL)
        return NULL;
    else{
        size_t addr = (size_t)p + align + sizeof(size_t);

        void *ptr = (void *)(addr - (addr%align));

        return ptr;
    }
}

void * aligned_free(void *ptr) {
        void *p = (void *)(*((size_t *)ptr - 1));
        free(p);
}
