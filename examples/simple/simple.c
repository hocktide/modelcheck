/**
 * \file examples/simple/simple.c
 *
 * Simple example of the model checker in action.
 *
 * \copyright 2019 Justin Handville.  Please see LICENSE.txt in this
 * distribution for more information.
 */

#include <stdint.h>
#include <modelcheck/allocator.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int32_t* buf = NULL;

    buf = (int32_t*)malloc(10*sizeof(int32_t));
    if (NULL == buf)
        return 1;

    buf[0] = 100;
    buf[1] = buf[0] << 1;
    buf[2] = buf[1] << 1;
    buf[3] = buf[2] << 1;
    buf[4] = buf[3] << 1;
    buf[5] = buf[4] << 1;
    buf[6] = buf[5] << 1;
    buf[7] = buf[6] << 1;
    buf[8] = buf[7] << 1;
    buf[9] = buf[8] << 1;

    free(buf);
}
