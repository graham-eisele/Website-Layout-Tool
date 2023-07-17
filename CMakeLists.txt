cmake_minimum_required(VERSION 3.27.0)

project(Website-Layout-Tool)

set(OpenCV_DIR C:/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} source/src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})