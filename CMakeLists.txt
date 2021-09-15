project(Google_Tests)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run NoteTest.cpp CollectionTest.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
