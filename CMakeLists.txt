cmake_minimum_required(VERSION 3.12)
project(Road_Fighter)

set(EXECUTABLE_NAME "Road_Fighter")

set(CMAKE_CXX_STANDARD 14)

add_executable(${EXECUTABLE_NAME} main.cpp Entity.cpp Entity.h PlayerCar.cpp PlayerCar.h RacingCar.cpp RacingCar.h PassingCar.cpp PassingCar.h Bullet.cpp Bullet.h World.cpp World.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)