cmake_minimum_required(VERSION 3.27.0)

project(Website-Layout-Tool)

set(OpenCV_DIR C:/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} 

    source/src/main.cpp 

    source/headers/Box.h
    source/headers/Button.h
    source/headers/CheckMark.h
    source/headers/CImg.h
    source/headers/Color.h
    source/headers/RadioOption.h
    source/headers/Text.h
    source/headers/TextBox.h
    source/headers/ImagePlaceholder.h
    source/headers/Captcha.h
    source/headers/utils.h 
    source/headers/Layout.h

    source/src/Box.cpp
    source/src/Button.cpp
    source/src/CheckMark.cpp
    source/src/Color.cpp
    source/src/main.cpp
    source/src/RadioOption.cpp
    source/src/Text.cpp
    source/src/TextBox.cpp
    source/src/ImagePlaceholder.cpp
    source/src/Captcha.cpp
    source/src/utils.cpp
    source/src/Layout.cpp
    )
    

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})