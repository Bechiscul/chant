cmake_minimum_required(VERSION 3.10)


set(SOURCES
    main.c)

message(${CMAKE_C_COMPILE_FEATURES})

add_executable(Compiler)
target_compile_features(Compiler PRIVATE c_std_11)
target_sources(Compiler PRIVATE ${SOURCES})