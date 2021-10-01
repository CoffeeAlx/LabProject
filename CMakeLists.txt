cmake_minimum_required(VERSION 3.20)
project(ObserverNotes)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Google_tests)

set(SOURCE_FILES Note.cpp Note.h Collection.cpp Collection.h Observer.h Subject.h Viewer.h)
add_executable(ObserverNotes main.cpp)
add_library(gtest ${SOURCE_FILES})
target_link_libraries(ObserverNotes gtest)
