cmake_minimum_required (VERSION 2.8)

project(Test)

aux_source_directory(./ DIR_SRCS)

add_executable(Demo ${DIR_SRCS})
