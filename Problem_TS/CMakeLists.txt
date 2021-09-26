cmake_minimum_required(VERSION 3.13)

# set ${PROJECT_NAME} and version
project(Problem_TS VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC src/main.cc src/text_sortion/text_sortion.cc src/text_sortion/text_sortion.cc)

add_executable(Problem_TS ${SRC})

target_include_directories(Problem_TS PUBLIC src/text_sortion)
target_compile_options(Problem_TS INTERFACE "-Wall -Wextra")