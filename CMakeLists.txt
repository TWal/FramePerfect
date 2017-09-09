cmake_minimum_required (VERSION 2.6)

project(FramePerfect)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")
set(CMAKE_CXX_FLAGS "-g -Wall -pedantic -std=c++17")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_custom_target(mrproper
   COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/CMakeModules/mrproper.cmake
)

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
list(APPEND LIBS ${SFML_LIBRARIES})

file(GLOB_RECURSE sources_files src/*)

add_executable(${PROJECT_NAME} ${sources_files})
target_link_libraries(${PROJECT_NAME} ${LIBS})
