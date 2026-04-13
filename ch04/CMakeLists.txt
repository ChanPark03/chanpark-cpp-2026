cmake_minimum_required(VERSION 3.16)

project(ch03_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB CH03_CPP_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

foreach(cpp_file IN LISTS CH03_CPP_FILES)
    file(SIZE "${cpp_file}" source_size)
    if(source_size EQUAL 0)
        get_filename_component(file_name "${cpp_file}" NAME)
        message(STATUS "Skipping empty source: ${file_name}")
        continue()
    endif()

    get_filename_component(file_stem "${cpp_file}" NAME_WE)
    add_executable("${file_stem}" "${cpp_file}")
endforeach()
