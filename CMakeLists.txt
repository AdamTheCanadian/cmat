cmake_minimum_required(VERSION 3.0)
project(cmat)

if (NOT TARGET ctest)
    add_subdirectory(../ctest ${PROJECT_BINARY_DIR}/ctest)
endif()

include_directories(include)

add_library(${PROJECT_NAME}
        src/mat3f.c
        src/mat4f.c
        src/vec3f.c
        src/vec3d.c
        src/mat3d.c
        src/vec.c
        src/angles.c)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_executable(${PROJECT_NAME}_unit_tests
        tests/main.c)

target_link_libraries(${PROJECT_NAME}_unit_tests
        ${PROJECT_NAME}
        ctest)

add_custom_command(
        TARGET ${PROJECT_NAME}_unit_tests
        POST_BUILD
        COMMAND ${PROJECT_NAME}_unit_tests)