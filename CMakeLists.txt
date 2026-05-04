cmake_minimum_required(VERSION 4.3)
project(Restaurant)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(RAYLIB_SOURCES "C:/raylib/raylib/src")

set(CHARACTER_IMAGES_AMOUNT 8)
set(CHARACTER_PATH "images/character")
set(REVERSED_CHARACTER_PATH "images/character_reversed")
set(VIEW_HEIGHT 800)
set(VIEW_WIDTH 450)
set(CHARACTER_SPEED 5)

configure_file(gusfood_config.h.in gusfood_config.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
main.cpp
src/view.cpp
src/controller.cpp
src/game_events.cpp
src/gusfood_model.cpp
src/key_binding.cpp
src/observable.cpp
src/observer.cpp
src/entity.cpp
src/map.cpp
)

target_include_directories(Restaurant PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
  "${RAYLIB_SOURCES}"
  "${PROJECT_BINARY_DIR}"
)

target_link_directories(Restaurant PRIVATE
  ${RAYLIB_SOURCES}
)

target_link_libraries(Restaurant
  raylib
  gdi32
  winmm
)