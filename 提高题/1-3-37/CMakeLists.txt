cmake_minimum_required (VERSION 2.8)

project (Demo)

aux_source_directory(./ DIR_SRCS)

add_executable(Demo ${DIR_SRCS})


# add_subdirectory(Queue)
# add_executable(Demo main.cc)
# target_link_libraries(Demo Queue)