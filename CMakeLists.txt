cmake_minimum_required (VERSION 3.3)

project(FramePerfect)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_custom_target(mrproper
   COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/CMakeModules/mrproper.cmake
)

add_custom_target(doc
  COMMAND doxygen
  COMMAND ln -fs doc/html/index.html index.html
)

include_directories(thirdparty/json/include)

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
list(APPEND LIBS ${SFML_LIBRARIES})

find_package(spdlog REQUIRED)
include_directories(${SPDLOG_INCLUDE_DIR})

file(GLOB_RECURSE sources_files src/*)

add_executable(${PROJECT_NAME} ${sources_files})
target_link_libraries(${PROJECT_NAME} ${LIBS})


# Custom config vars
set(BFRAME_SIZE 200 CACHE INTEGER "The number of patches before recording a full model again")
if(BFRAME_SIZE MATCHES "^[0-9]+$")
  add_definitions(-DBFRAME_SIZE=${BFRAME_SIZE})
else()
  message( SEND_ERROR "BFRAME_SIZE must be a unsigned integer" )
endif()

set(LOG_LEVELS trace debug info warning error critical)

set(LOG_LEVEL debug CACHE STRING
  "The base log level. Must be : trace debug info warning error critical")
if( ${LOG_LEVEL} IN_LIST LOG_LEVELS )
  add_definitions(-DLOG_LEVEL=${LOG_LEVEL})
  if(LOG_LEVEL MATCHES "trace")
    add_definitions(-DSPDLOG_TRACE_ON)
    add_definitions(-DSPDLOG_DEBUG_ON)
  elseif(LOG_LEVEL MATCHES "debug")
    add_definitions(-DSPDLOG_DEBUG_ON)
  endif()
else()
  message( SEND_ERROR "LOG_LEVEL is not one of trace debug info warning error critical" )
endif()

set(LOG_FILE log CACHE STRING "The log file")
add_definitions(-DLOG_FILE="${LOG_FILE}")

