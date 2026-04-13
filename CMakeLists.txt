cmake_minimum_required(VERSION 3.20)

project(chanpark_cpp_2026 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(add_standalone_example target_name source_file output_name)
    add_executable("${target_name}" "${source_file}")
    set_target_properties("${target_name}" PROPERTIES OUTPUT_NAME "${output_name}")
endfunction()

function(add_chapter_examples chapter_name)
    file(GLOB chapter_cpp_sources CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/${chapter_name}/*.cpp"
    )

    foreach(source_file IN LISTS chapter_cpp_sources)
        file(SIZE "${source_file}" source_size)
        if(source_size EQUAL 0)
            get_filename_component(source_name "${source_file}" NAME_WE)
            message(STATUS "Skipping empty source: ${chapter_name}/${source_name}.cpp")
            continue()
        endif()

        get_filename_component(source_name "${source_file}" NAME_WE)
        add_standalone_example("${chapter_name}_${source_name}" "${source_file}" "${source_name}")
    endforeach()
endfunction()

add_chapter_examples(ch01)
add_chapter_examples(ch02)
add_chapter_examples(ch03)
add_chapter_examples(ch04)

add_standalone_example(root_main "${CMAKE_CURRENT_SOURCE_DIR}/main.c" "main")

add_subdirectory(ch02/namespace)
add_subdirectory(test01/test)
