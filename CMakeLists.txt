cmake_minimum_required(VERSION 3.20)
project(ObserverNotes)

set(CMAKE_CXX_STANDARD 11)

add_executable(ObserverNotes main.cpp Note.cpp Note.h Collection.cpp Collection.h Observer.h Subject.h Google_Tests/CollectionTest.cpp Google_Tests/NoteTest.cpp)
add_subdirectory(Google_tests)