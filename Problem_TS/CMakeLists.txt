cmake_minimum_required(VERSION 3.13)

# set ${PROJECT_NAME} and version
project(Problem_TS VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC src/main.cc 
        src/text_sortion/text_sortion.cc
        src/m_qsort/m_qsort.cc
        src/err_proc/err_proc.cc
        src/my_str/my_str.cc)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC src/text_sortion src/m_qsort src/my_str src/err_proc)
target_compile_options(${PROJECT_NAME} INTERFACE "-g -Wall -Wextra")