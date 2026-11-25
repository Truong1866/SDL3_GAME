cmake_minimum_required(VERSION 4.2)
project(SDL3_GAME)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG        v4.0.0
)
FetchContent_MakeAvailable(entt)

FetchContent_Declare(
        tomlplusplus
        GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(tomlplusplus)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(glm CONFIG REQUIRED)
add_executable(SDL3_GAME
        src/main.cpp

        src/Config/ConfigLoader.cpp
        src/Config/ConfigManager.cpp
        src/Config/ConfigValidator.cpp

        src/Core/AssetManager.cpp
        src/Core/InputManager.cpp
        src/Core/SDL_State.cpp
        src/Core/PlayerFactory.cpp
        src/Core/Game.cpp

        src/Systems/Animation.cpp
        src/Systems/PhysicalSystem.cpp
        src/Systems/RenderSystem.cpp
        src/Systems/PlayerStateSystem.cpp
        src/Systems/TransformSystem.cpp
)
target_include_directories(SDL3_GAME PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(SDL3_GAME PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        EnTT::EnTT
        glm::glm
        tomlplusplus::tomlplusplus
)
add_custom_command(TARGET SDL3_GAME POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:SDL3_GAME>/data
)

