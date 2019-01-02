cmake_minimum_required(VERSION 3.12)
project(Road_Fighter)

set(EXECUTABLE_NAME "Road_Fighter")

set(CMAKE_CXX_STANDARD 14)

add_library(RoadFighter STATIC source/Logic/Entity.cpp source/Logic/Entity.h source/Logic/PlayerCar.cpp source/Logic/PlayerCar.h source/Logic/RacingCar.cpp source/Logic/RacingCar.h source/Logic/PassingCar.cpp source/Logic/PassingCar.h source/Logic/Bullet.cpp source/Logic/Bullet.h source/Logic/World.cpp source/Logic/World.h)

add_executable(${EXECUTABLE_NAME} source/main.cpp source/Game.cpp source/Game.h source/Logic/Random.cpp source/Logic/Random.h source/Logic/Transformation.cpp source/Logic/Transformation.h source/sfmlgraph/PlayerCarSFML.cpp source/sfmlgraph/PlayerCarSFML.h source/sfmlgraph/WorldSFML.cpp source/sfmlgraph/WorldSFML.h)

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