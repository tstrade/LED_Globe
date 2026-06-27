#ifndef __DBLALOCK_ALIGN_H__
#define __DBLALOCK_ALIGN_H__

#include <stdlib.h>
#include "macros.h"

void * aligned_alloc (size_t alignment, size_t size, bool zero);
void aligned_free (void * aligned_ptr);

#endif /* __DBLALOCK_ALIGN_H__ */