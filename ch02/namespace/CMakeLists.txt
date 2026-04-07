add_executable(ch02_namespace
    main.cpp
    kitae.cpp
    mike.cpp
)

target_include_directories(ch02_namespace PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

get_filename_component(output_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
set_target_properties(ch02_namespace PROPERTIES
    OUTPUT_NAME "${output_name}"
)
