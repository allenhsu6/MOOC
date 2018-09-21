cmake_minimum_required(VERSION 3.12)
project(learnc C)

set(CMAKE_C_STANDARD 99)

add_executable(learnc main.c poly.h poly.c BinarySearch.c BinarySearch.h Student.c Student.h Search.c Search.h Tree.c Tree.h)