cmake_minimum_required(VERSION 3.12)
project(learnc C)

set(CMAKE_C_STANDARD 99)

add_executable(learnc main.c poly.h poly.c BinarySearch.c BinarySearch.h Student.c Search.c Search.h Tree.c Tree.h List.c List.h Stack.c Stack.h)
add_executable(learntree StructTree.c)
