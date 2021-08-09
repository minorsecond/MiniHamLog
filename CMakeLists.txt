cmake_minimum_required(VERSION 3.17)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum OS X deployment version")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(MiniHamLog)
set(LIBPROC_SRC "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/libproc.h")
set(CMAKE_PREFIX_PATH "/Users/rwardrup/Qt/6.0.4/clang_64/")

find_package(Qt6 COMPONENTS Core Widgets PrintSupport Gui REQUIRED)

add_executable(MiniHamLog src/main.cpp src/Contact.cpp src/Contact.h src/Datetime.cpp src/Datetime.h src/Utilities.cpp
        src/Utilities.h src/mainwindow.cpp src/mainwindow.h ui/ui_mainwindow.h)

target_link_libraries(MiniHamLog Qt6::Core Qt6::Widgets Qt6::PrintSupport Qt6::Gui SQLite3 "-framework CoreFoundation")