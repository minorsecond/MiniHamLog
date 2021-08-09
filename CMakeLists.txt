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
find_package(SQLite3 REQUIRED)
find_package(Catch2 REQUIRED)

add_executable(MiniHamLog src/main.cpp src/Contact.cpp src/Contact.h src/Datetime.cpp src/Datetime.h src/Utilities.cpp
        src/Utilities.h src/mainwindow.cpp src/mainwindow.h ui/ui_mainwindow.h include/sqlite_orm.h)

target_link_libraries(MiniHamLog Qt6::Core Qt6::Widgets Qt6::PrintSupport Qt6::Gui SQLite3 "-framework CoreFoundation")

set_target_properties(MiniHamLog PROPERTIES
        MACOSX_BUNDLE_BUNDLE_NAME "MiniHamLog"
        MACOSX_BUNDLE_BUNDLE_VERSION "0.0.1"
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_ICON_FILE icon.icns
        MACOSX_BUNDLE_LONG_VERSION_STRING "0.0.1"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "0.0.1"
        MACOSX_BUNDLE_COPYRIGHT "2021 Ross Wardrup"
        MACOSX_BUNDLE_GUI_IDENTIFIER com.rwardrup.minihamlog
        XCODE_ATTRIBUTE_LD_RUNPATH_SEARCH_PATHS "@loader_path/Libraries"
        XCODE_ATTRIBUTE_ENABLE_HARDENED_RUNTIME TRUE
        XCODE_ATTRIBUTE_EXECUTABLE_NAME "minihamlog")