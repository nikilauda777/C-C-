cmake_minimum_required(VERSION 3.17)
project(programm1)

set(CMAKE_CXX_STANDARD 20)

add_executable(programm1 programm.cpp cmake-build-debug/StadtReader.cpp cmake-build-debug/StadtReader.h stadt.h strasse.h gebiet.h randomtrip.h)