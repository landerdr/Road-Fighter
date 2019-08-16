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
Space | Shoot bullet (1s delay)
Escape | Closes game

In menu

Button | Action
------|-------
Z | Move up
S | Move down
Enter | Select option
Escape | Closes game

#### Game Rules

The goal from the game is to get to the finish, with as much points as possible.

- The green cars are race cars, they will race you for the entire game, you can slow them down by shooting them, if you collide with them, both yourself and the car will lose some speed.
- The blue cars are type 1 passing cars, you can destroy them by shooting them, if you hit them you will lose a big amount of speed, and points. The car gets removed on impact (explodes).
- The pink cars are type 2 passing cars, they can also be destroyed by shooting them, but if you hit them, you will receive a big speed boost. The car gets removed on impact (explodes).
- You have unlimited ammo, however the bullets have a time delay, which can be set in the config file (default = 1s).
- The yellow car is the boss car, this type of computer controlled entity can do anything the player can.

#### Level Overview

Level | Content
---- | ----
1 | Traditional level where you race against computer controlled entities with obstacles.
2 | "Party mode" where you only need to dodge obstacles.
3 | Boss level, the boss is a special computer controlled entity that will shoot and try to race you to the finish.

### Important note on config files

The project has it's own custom file reader, this can read following format:
```
// The reader supports comments
Key:Value
Key2:Value2
// It also supports white spaces

// However because of the way it checks for the file end (it looks for duplicate lines)
// it won't accept two whitespace lines as it won't read any of the following values anymore


// So this part wouldn't be read anymore.
Key3:Value3
```

The file reader is easily expanded upon and throws custom exceptions when it doesn't find the key, or you request an incorrect type.
