cmake_minimum_required(VERSION 3.10)
project(ChantTests LANGUAGES C)

enable_testing()
include(CTest)

add_executable(tokenizer tokenizer.c)
add_test(NAME tokenizer COMMAND tokenizer)
