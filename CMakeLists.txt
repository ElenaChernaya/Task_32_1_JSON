cmake_minimum_required(VERSION 3.16)
project(Task_32_1_JSON)

set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL " ")

add_subdirectory(nlohmann_json)
add_executable(Task_32_1_JSON main.cpp)

target_link_libraries(Task_32_1_JSON PRIVATE nlohmann_json::nlohmann_json)
