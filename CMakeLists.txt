cmake_minimum_required(VERSION 3.19)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Mandelbrot src/main.cpp src/Mandelbrot.cpp src/Mandelbrot.h)

target_link_libraries(Mandelbrot sfml-graphics sfml-audio)