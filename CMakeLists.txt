cmake_minimum_required(VERSION 3.13)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp utility.h Datas.cpp Datas.h Search.h Search.cpp KMP.h KMP.cpp Cos.h Cos.cpp Jaccard.h Jaccard.cpp)