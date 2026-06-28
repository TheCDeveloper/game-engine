cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(game-engine VERSION 0.1.0 LANGUAGES C)

find_package(SDL3 REQUIRED)


file(GLOB ENGINE_SOURCES "src/engine/*.c" "src/engine/types/*.c")
add_library(game-engine SHARED ${ENGINE_SOURCES})
target_include_directories(game-engine PUBLIC "src/engine/include")
target_link_libraries(game-engine PRIVATE SDL3::SDL3)

file(GLOB TEST_SOURCES "src/test/*.c")
add_executable(test ${TEST_SOURCES})
target_link_libraries(test PRIVATE game-engine)
