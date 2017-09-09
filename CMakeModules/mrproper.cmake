set(cmake_generated ${CMAKE_BINARY_DIR}/CMakeCache.txt
                    ${CMAKE_BINARY_DIR}/cmake_install.cmake
                    ${CMAKE_BINARY_DIR}/compile_commands.json
                    ${CMAKE_BINARY_DIR}/Makefile
                    ${CMAKE_BINARY_DIR}/CMakeFiles
                    ${CMAKE_BINARY_DIR}/doc
                    ${CMAKE_BINARY_DIR}/index.html
)

foreach(file ${cmake_generated})
    if (EXISTS ${file})
        file(REMOVE_RECURSE ${file})
    endif()
endforeach(file)
