cmake_minimum_required(VERSION 3.20)

set(INCLUDES
    lexical.hpp
    tokenizer.hpp)

set(SOURCES
    main.cpp
    tokenizer.cpp)

add_executable(Compiler)
target_sources(Compiler PRIVATE ${INCLUDES} ${SOURCES})
target_compile_features(Compiler PRIVATE cxx_std_20)
target_include_directories(Compiler PUBLIC "../")