cmake_minimum_required(VERSION 3.12)
project(Road_Fighter)

set(EXECUTABLE_NAME "Road_Fighter")

set(CMAKE_CXX_STANDARD 14)

add_library(RoadFighter STATIC source/Entity.cpp source/Entity.h source/PlayerCar.cpp source/PlayerCar.h source/RacingCar.cpp source/RacingCar.h source/PassingCar.cpp source/PassingCar.h source/Bullet.cpp source/Bullet.h source/World.cpp source/World.h)

add_executable(${EXECUTABLE_NAME} source/main.cpp source/Game.cpp source/Game.h source/Random.cpp source/Random.h source/Transformation.cpp source/Transformation.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.4 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

target_link_libraries(${EXECUTABLE_NAME} RoadFighter)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)