cmake_minimum_required(VERSION 3.16)

project(ch02_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB CH02_CPP_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

foreach(cpp_file IN LISTS CH02_CPP_FILES)
    get_filename_component(file_stem "${cpp_file}" NAME_WE)
    set(target_name "${file_stem}")

    add_executable("${target_name}" "${cpp_file}")
endforeach()

file(GLOB CH02_CHILDREN CONFIGURE_DEPENDS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

foreach(child IN LISTS CH02_CHILDREN)
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}"
       AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
        add_subdirectory("${child}")
    endif()
endforeach()
