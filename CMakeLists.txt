cmake_minimum_required(VERSION 4.2)
project(SDL3_GAME)

set(CMAKE_CXX_STANDARD 26)
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
add_executable(SDL3_GAME src/main.cpp
        src/SDL_State.cpp
        include/SDL_State.h)
target_include_directories(SDL3_GAME PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(SDL3_GAME PRIVATE SDL3::SDL3)
target_link_libraries(SDL3_GAME PRIVATE SDL3_image::SDL3_image)
add_custom_command(TARGET SDL3_GAME POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:SDL3_GAME>/data
)

