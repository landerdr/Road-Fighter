cmake_minimum_required(VERSION 3.13)
project(Road_Fighter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Road_Fighter main.cpp Entity.cpp Entity.h PlayerCar.cpp PlayerCar.h RacingCar.cpp RacingCar.h PassingCar.cpp PassingCar.h Bullet.cpp Bullet.h World.cpp World.h)