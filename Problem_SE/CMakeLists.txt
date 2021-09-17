cmake_minimum_required(VERSION 3.13)

# set ${PROJECT_NAME} and version
project(Problem_SE VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR}/build/CMakeDoxyfile.in)
    set(DOXYGEN_OUTPUT ${CMAKE_SOURCE_DIR}/docs/Doxyfile)

    configure_file(${DOXYGEN_INPUT} ${DOXYGEN_OUTPUT})

    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/docs/Doxyfile)

else()
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif(DOXYGEN_FOUND)

set(SRC src/main.cpp src/eq_solver/eq_solver.cpp  src/common/test.cpp)

add_executable(Problem_SE ${SRC})

target_include_directories(Problem_SE PUBLIC src/eq_solver src/common)
target_compile_options(Problem_SE INTERFACE "-Wall -Wextra")