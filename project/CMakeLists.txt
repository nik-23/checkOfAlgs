cmake_minimum_required(VERSION 3.24)
project(corser C)

set(CMAKE_C_STANDARD 11)

add_executable(corser Measurements.h  sorting_algorithms.h sorting_algorithms.c out_of_vec.h out_of_vec.c Measurements.c main.c arr_and_vec_utils.c arr_and_vec_utils.h)