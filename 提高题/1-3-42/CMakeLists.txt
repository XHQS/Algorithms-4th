cmake_minimum_required (VERSION 2.8)

project(Demo)

aux_source_directory(./ DIR_SRC)

add_subdirectory(stack)

add_executable(Demo main.cc)

target_link_libraries(Demo Stack)