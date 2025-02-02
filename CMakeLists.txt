cmake_minimum_required(VERSION 3.15)

project(HOMEWORK_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)
include_directories(./include)

set(SOURCE_FILES 
    ./test/main.cpp
    ./src/vector.cpp
    ./test/test_vector.cpp
     )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(alltest ${SOURCE_FILES})
target_link_libraries(alltest PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads)