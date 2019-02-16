PROJECT(modelcheck)

cmake_minimum_required(VERSION 3.10)

INCLUDE_DIRECTORIES(include)

#Build a pkg-config file
SET(MODELCHECK_PC "${CMAKE_BINARY_DIR}/modelcheck.pc")
FILE(WRITE  ${MODELCHECK_PC} "Name: modelcheck")
FILE(APPEND ${MODELCHECK_PC} "\nDescription: modelcheck model checking helpers")
FILE(APPEND ${MODELCHECK_PC} "\nVersion: 0.1.0")
FILE(APPEND ${MODELCHECK_PC} "\nURL: https://github.com/nanolith/modelcheck")
FILE(APPEND ${MODELCHECK_PC} "\nprefix=${CMAKE_INSTALL_PREFIX}")
FILE(APPEND ${MODELCHECK_PC} "\nlibdir=\${prefix}/lib")
FILE(APPEND ${MODELCHECK_PC} "\nincludedir=\${prefix}/include")
FILE(APPEND ${MODELCHECK_PC} "\nallocator_sources=")
FILE(APPEND ${MODELCHECK_PC} "\${prefix}/share/modelcheck/src/allocator.c")
FILE(APPEND ${MODELCHECK_PC} "\nCflags: -I\${includedir}")
INSTALL(FILES ${MODELCHECK_PC} DESTINATION lib/pkgconfig)

FILE(GLOB MODELCHECK_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/include/modelcheck/*.h")
FILE(GLOB MODELCHECK_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
INSTALL(FILES ${MODELCHECK_INCLUDES} DESTINATION include/modelcheck)
INSTALL(FILES ${MODELCHECK_SOURCES} DESTINATION share/modelcheck/src)

ADD_CUSTOM_TARGET(run_tests COMMAND echo "all tests complete")
ADD_SUBDIRECTORY(examples)
