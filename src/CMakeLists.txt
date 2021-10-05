cmake_minimum_required(VERSION 3.10)

set(INCLUDES
    tokenizer.h)

set(SOURCES
    main.c
    tokenizer.c
    )

message(${CMAKE_C_COMPILE_FEATURES})

add_executable(Compiler)
target_compile_features(Compiler PRIVATE c_std_11)
target_sources(Compiler PRIVATE ${INCLUDES} ${SOURCES})