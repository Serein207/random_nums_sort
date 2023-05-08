cmake_minimum_required (VERSION 2.8) 

project (random_nums_sort)

set (CMAKE_CXX_STANDARD 17)

aux_source_directory (src/. DIR_SRCS)

add_executable(main ${DIR_SRCS} "src/file_handler.cpp")