/**
 * \file allocator.c
 *
 * Implementation of model checking allocator overrides.
 *
 * \copyright 2019 Justin Handville.  Please see LICENSE.txt in this
 * distribution for more information.
 */
#define MODEL_MALLOC_IMPL
#include <modelcheck/allocator.h>
#include <modelcheck/model_assert.h>
#include <stdlib.h>

/* Enable this compilation unit only under MODEL_CHECK. */
#ifdef MODEL_CHECK

/**
 * Non-deterministic boolean value, provided by the model checker.
 *
 * \returns true or false in a nondeterministic manner.
 */
_Bool nondet_bool();

/**
 * Perform a model checked allocation procedure that can fail
 * nondeterministically.
 *
 * \param size      The size of the memory region to allocate.
 *
 * \returns a pointer to a newly allocated memory region of the given size, or
 *          NULL if allocation fails.
 */
void* model_malloc(size_t size)
{
    if (nondet_bool())
    {
        return malloc(size);
    }
    else
    {
        return NULL;
    }
}

/**
 * Free a memory region previously allocated by model_malloc.
 *
 * \note - this routine asserts that the pointer is not NULL.  If this assertion
 * can fail, then the model checker will report an error.
 */
void model_free(void* ptr)
{
    MODEL_ASSERT(ptr != NULL);
    MODEL_ASSERT(__CPROVER_DYNAMIC_OBJECT(ptr));
    free(ptr);
}

#endif /* defined MODEL_CHECK */
