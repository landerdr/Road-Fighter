cmake_minimum_required(VERSION 3.8)
project(Road_Fighter)

set(EXECUTABLE_NAME "Road_Fighter")

set(CMAKE_CXX_STANDARD 14)

add_executable(${EXECUTABLE_NAME} main.cpp Entity.cpp Entity.h PlayerCar.cpp PlayerCar.h RacingCar.cpp RacingCar.h PassingCar.cpp PassingCar.h Bullet.cpp Bullet.h World.cpp World.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})