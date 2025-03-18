cmake_minimum_required(VERSION 3.15)

project(HOMEWORK_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)
include_directories(./include)
include_directories(./test/mock)

set(SOURCE_FILES 
    ./test/main.cpp
    ./src/vector.cpp
    ./src/direction.cpp
    ./src/move.cpp
    ./src/rotate.cpp
    ./test/test_vector.cpp
    ./test/test_direction.cpp
    ./test/test_move.cpp
    ./test/test_rotate.cpp
    ./src/commandprocessor.cpp
    ./test/test_commandprocessor.cpp
    ./test/test_logcommand.cpp
    ./test/test_logexceptioncommand.cpp
    ./test/test_example_logbyexception.cpp
    ./test/test_repeatedcommand.cpp
    ./test/test_repeatcommandhandler.cpp
     )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(alltest ${SOURCE_FILES})
target_link_libraries(alltest PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads)