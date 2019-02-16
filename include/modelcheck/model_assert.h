/**
 * \file model_check/model_assert.h
 *
 * \brief Model assertions.
 *
 * When the MODEL_CHECK macro is defined, MODEL_ASSERT will add an assertion to
 * the code.
 *
 * \copyright 2019 Justin Handville.  Please see LICENSE.txt in this
 * distribution for more information.
 */

#ifndef  MODEL_CHECK_MODEL_ASSERT_HEADER_GUARD
# define MODEL_CHECK_MODEL_ASSERT_HEADER_GUARD

#ifdef   __cplusplus
extern "C" {
#endif /*__cplusplus*/

#include <assert.h>

#ifdef MODEL_CHECK
# define MODEL_ASSERT(x) __CPROVER_assert((x), #x)
#else
# define MODEL_ASSERT(x)
#endif

#ifdef   __cplusplus
}
#endif /*__cplusplus*/

#endif /*MODEL_CHECK_MODEL_ASSERT_HEADER_GUARD*/
