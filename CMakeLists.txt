cmake_minimum_required(VERSION 4.3)
project(Restaurant)

set(RAYLIB_SOURCES "C:/raylib/raylib/src")

set(CHARACTER_IMAGES_AMOUNT 8)
set(CHARACTER_PATH "images/character")
set(REVERSED_CHARACTER_PATH "images/character_reversed")
set(VIEW_HEIGHT 800)
set(VIEW_WIDTH 450)
set(CHARACTER_SPEED 5)

configure_file(restau_config.h.in restau_config.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
main.cpp
src/model/observable.cpp
src/model/observer.cpp
)

target_include_directories(Restaurant PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src/view"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/model"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/controller"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
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