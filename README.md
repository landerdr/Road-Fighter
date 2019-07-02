# Road-Fighter
[![Build Status](https://travis-ci.com/landerdr/Road-Fighter.svg?token=kHdYqstEjn9LocAvPi4v&branch=master)](https://travis-ci.com/landerdr/Road-Fighter)

Clang format file from: [here](https://github.com/broeckho/prog2)

Important: To run game either use run.sh or change working directory to the root from this repo.

#### Game Controls

Button | Action
------|-------
Z | Accelerate (max 600km/h)
S | Decelerate (min 200km/h)
Q | Move left
D | Move right
Space | Shoot bullet (only 1 at a time on screen)
Escape | Closes game

#### Game Rules

The goal from the game is to get to the finish, with as much points as possible.

- The green cars are race cars, they will race you for the entire game, you can slow them down by shooting them, if you collide with them, both yourself and the car will lose some speed.
- The blue cars are type 1 passing cars, you can destroy them by shooting them, if you hit them you will lose a big amount of speed, and points. The car gets removed on impact (explodes).
- The pink cars are type 2 passing cars, they can also be destroyed by shooting them, but if you hit them, you will receive a big speed boost. The car gets removed on impact (explodes).
- You have unlimited ammo, but you can only shoot 1 bullet at a time.