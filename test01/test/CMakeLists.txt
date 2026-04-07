add_executable(test01_test
    main.c
    a.c
    b.c
)

target_include_directories(test01_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

get_filename_component(output_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
set_target_properties(test01_test PROPERTIES
    OUTPUT_NAME "${output_name}"
)
