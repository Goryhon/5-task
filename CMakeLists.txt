
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

if(NOT MODE)
    set(MODE File)
endif()

add_library(MATRIX_MATH SHARED MatrixMath.cpp MatrixMath.h)
add_library(MATRIX${MODE}PRINT SHARED Matrix${MODE}Print.cpp Matrix${MODE}Print.h PrintTo.cpp PrintTo.h)

add_executable(MAIN main.cpp)

target_link_libraries(MAIN MATRIX_MATH MATRIX${MODE}PRINT)

add_subdirectory(googletest)

add_executable(test test.cpp)

target_link_libraries(test MATRIX${MODE}PRINT MATRIX_MATH gtest gtest_main)
