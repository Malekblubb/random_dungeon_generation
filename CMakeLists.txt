project(dungeon_generation)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
add_library(HEADER_ONLY STATIC "room_generator.hpp" "field.hpp" "room.hpp" "point")
include_directories("external/mlk/include")
set_target_properties(HEADER_ONLY PROPERTIES LINKER_LANGUAGE CXX)
SET(CMAKE_CXX_FLAGS "-std=c++11")
