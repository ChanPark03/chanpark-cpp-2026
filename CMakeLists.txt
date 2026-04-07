cmake_minimum_required(VERSION 3.20)

project(chanpark_cpp_2026 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(add_standalone_example target_name source_file)
    add_executable("${target_name}" "${source_file}")
endfunction()

file(GLOB CH01_CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/ch01/*.cpp"
)

foreach(source_file IN LISTS CH01_CPP_SOURCES)
    get_filename_component(source_name "${source_file}" NAME_WE)
    add_standalone_example("ch01_${source_name}" "${source_file}")
endforeach()

file(GLOB CH02_CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/ch02/*.cpp"
)

foreach(source_file IN LISTS CH02_CPP_SOURCES)
    get_filename_component(source_name "${source_file}" NAME_WE)
    add_standalone_example("ch02_${source_name}" "${source_file}")
endforeach()

add_standalone_example(root_main "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

add_subdirectory(ch02/namespace)
add_subdirectory(test01/test)
