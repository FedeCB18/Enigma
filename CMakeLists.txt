cmake_minimum_required(VERSION 3.31)
project(Final_Project)

set(CMAKE_CXX_STANDARD 20)

# Find SFML components
find_package(SFML COMPONENTS Graphics Window System REQUIRED)

add_executable(Final_Project main.cpp
        test.cpp)

# Link to SFML libraries
target_link_libraries(Final_Project PRIVATE SFML::Graphics SFML::Window SFML::System)
