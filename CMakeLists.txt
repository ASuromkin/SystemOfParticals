cmake_minimum_required(VERSION 3.22)
project(SystemOfParticals)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "/usr/include/SFML")
find_package(SFML COMPONENTS graphics window system)

add_executable(SystemOfParticals
        main.cpp engine.cpp missile.cpp)
target_link_libraries(SystemOfParticals sfml-graphics sfml-audio)