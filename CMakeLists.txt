cmake_minimum_required(VERSION 3.10)
project(Road_Fighter)

set(EXECUTABLE_NAME "Road_Fighter")

set(CMAKE_CXX_STANDARD 14)

add_library(RoadFighterCore STATIC
        source/Logic/Entity.cpp source/Logic/Entity.h
        source/Logic/PlayerCar.cpp source/Logic/PlayerCar.h
        source/Logic/RacingCar.cpp source/Logic/RacingCar.h
        source/Logic/PassingCar.cpp source/Logic/PassingCar.h
        source/Logic/Bullet.cpp source/Logic/Bullet.h
        source/Logic/World.cpp source/Logic/World.h
        source/Logic/Random.cpp source/Logic/Random.h
        source/Logic/Transformation.cpp source/Logic/Transformation.h
        source/Logic/AbstractFactory.cpp source/Logic/AbstractFactory.h
        source/Logic/ScoreObserver.cpp source/Logic/ScoreObserver.h 
		source/Logic/HighSoreModule.cpp source/Logic/HighSoreModule.h
		source/Logic/Configuration.cpp source/Logic/Configuration.h
        source/Logic/ExceptionBase.cpp source/Logic/ExceptionBase.h
        source/Logic/Game.cpp source/Logic/Game.h)

add_executable(${EXECUTABLE_NAME} source/main.cpp
        source/sfmlgraph/GameSFML.cpp source/sfmlgraph/GameSFML.h
        source/sfmlgraph/PlayerCarSFML.cpp source/sfmlgraph/PlayerCarSFML.h
        source/sfmlgraph/WorldSFML.cpp source/sfmlgraph/WorldSFML.h
        source/sfmlgraph/AbstractFactorySFML.cpp source/sfmlgraph/AbstractFactorySFML.h
        source/sfmlgraph/RacingCarSFML.cpp source/sfmlgraph/RacingCarSFML.h
        source/sfmlgraph/PassingCarSFML.cpp source/sfmlgraph/PassingCarSFML.h
        source/sfmlgraph/BulletSFML.cpp source/sfmlgraph/BulletSFML.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.4 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

target_link_libraries(${EXECUTABLE_NAME} RoadFighterCore)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)