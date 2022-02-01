cmake_minimum_required (VERSION 2.6)

PROJECT(LEET-TEST)

ADD_SUBDIRECTORY(googletest)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 11)


INCLUDE_DIRECTORIES(./googletest/googletest/include)
INCLUDE_DIRECTORIES(./googletest/googlemock/include)

FIND_LIBRARY(LIB_GTEST gtest ./googletest/build/lib NO_DEFAULT_PATH)
FIND_LIBRARY(LIB_GMOCK gmock ./googletest/build/lib NO_DEFAULT_PATH)

#no runtime lib needed, ignore it
FIND_LIBRARY(RUNTIME_LIB rt /usr/lib  /usr/local/lib NO_DEFAULT_PATH)

link_libraries(${LIB_GMOCK} ${LIB_GTEST})

ADD_DEFINITIONS(
-O0 -g -W -Wall
-Wunused-variable -Wunused-parameter -Wunused-function -Wunused
-Wno-deprecated -Woverloaded-virtual -Wwrite-strings
-D__WUR= -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DTIXML_USE_STL
)

SET(SRC main.cpp
        test_recursion.cc)

ADD_EXECUTABLE(test ${SRC})
