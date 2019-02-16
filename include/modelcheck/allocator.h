/**
 * \file model_check/allocater.h
 *
 * \brief Allocator under model checking.
 *
 * This macro redefines malloc / free in terms of model_malloc / model_free.
 *
 * \copyright 2019 Justin Handville.  Please see LICENSE.txt in this
 * distribution for more information.
 */

#ifndef  MODEL_CHECK_ALLOCATOR_HEADER_GUARD
# define MODEL_CHECK_ALLOCATOR_HEADER_GUARD

#ifdef   __cplusplus
extern "C" {
#endif /*__cplusplus*/

#if defined(MODEL_CHECK) && !defined(MODEL_MALLOC_IMPL)
# define malloc(x) model_malloc(x)
# define free(x) model_free(x)

#include <stdlib.h>

/**
 * Perform a model checked allocation procedure that can fail
 * nondeterministically.
 *
 * \param size      The size of the memory region to allocate.
 *
 * \returns a pointer to a newly allocated memory region of the given size, or
 *          NULL if allocation fails.
 */
void* model_malloc(size_t size);

/**
 * Free a memory region previously allocated by model_malloc.
 *
 * \note - this routine asserts that the pointer is not NULL.  If this assertion
 * can fail, then the model checker will report an error.
 */
void model_free(void* ptr);

#endif

#ifdef   __cplusplus
}
#endif /*__cplusplus*/

#endif /*MODEL_CHECK_ALLOCATOR_HEADER_GUARD*/
