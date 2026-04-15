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

function(add_all_chapter_examples)
    file(GLOB top_level_entries CONFIGURE_DEPENDS LIST_DIRECTORIES true
        RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/*"
    )

    foreach(entry IN LISTS top_level_entries)
        set(entry_path "${CMAKE_CURRENT_SOURCE_DIR}/${entry}")
        if(NOT IS_DIRECTORY "${entry_path}")
            continue()
        endif()

        if(entry MATCHES "^\\.")
            continue()
        endif()

        if(entry MATCHES "^build")
            continue()
        endif()

        file(GLOB chapter_cpp_sources CONFIGURE_DEPENDS
            "${entry_path}/*.cpp"
        )

        if(chapter_cpp_sources)
            add_chapter_examples("${entry}")
        endif()
    endforeach()
endfunction()

add_all_chapter_examples()

add_standalone_example(root_main "${CMAKE_CURRENT_SOURCE_DIR}/main.c" "main")

add_subdirectory(ch02/namespace)
add_subdirectory(test01/test)
