ADD_CUSTOM_TARGET(
    check_simple
    COMMAND cbmc --bounds-check --pointer-check --memory-leak-check
                 --div-by-zero-check --signed-overflow-check
                 --unsigned-overflow-check --pointer-overflow-check
                 --conversion-check --trace --stop-on-fail -DMODEL_CHECK
                 --object-bits 16 --drop-unused-functions --unwind 10
                 --full-slice
                 -I ../../include
                 ../../src/allocator.c
                 simple.c
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

ADD_DEPENDENCIES(run_tests check_simple)
