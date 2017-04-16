cmake_minimum_required(VERSION 3.6)
project(Prog2C__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Movie.cpp
        Movie.h
        MovieDB.cpp
        MovieDB.h
        Rating.cpp
        Rating.h
        Ratings.cpp
        Ratings.h
        TimeCode.cpp
        TimeCode.h)

add_executable(Prog2C__ ${SOURCE_FILES})