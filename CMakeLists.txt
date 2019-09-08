cmake_minimum_required (VERSION 2.8)
project (TinyC)
aux_source_directory(. DIR_SRCS)
add_executable(tc ${DIR_SRCS})