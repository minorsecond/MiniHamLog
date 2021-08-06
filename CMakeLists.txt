cmake_minimum_required(VERSION 3.20)
project(MiniHamLog)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiniHamLog main.cpp src/Contact.cpp src/Contact.h src/Datetime.cpp src/Datetime.h src/Utilities.cpp src/Utilities.h)
