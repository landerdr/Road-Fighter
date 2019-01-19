//
// Created by lander on 12/10/18.
//

#include "World.h"

bool roadfighter::World::entityCollision(std::shared_ptr<roadfighter::Entity> ent1, std::shared_ptr<roadfighter::Entity> ent2) {
    bool left_x = ent1->getLeftX() > ent2->getLeftX() && ent1->getLeftX() < ent2->getRightX();
    bool right_x = ent1->getRightX() > ent2->getLeftX() && ent1->getRightX() < ent2->getRightX();
    bool upper_y = ent1->getUpperY() < ent2->getUpperY() && ent1->getUpperY() > ent2->getLowerY();
    bool lower_y = ent1->getLowerY() < ent2->getUpperY() && ent1->getLowerY() > ent2->getLowerY();

    return (left_x || right_x) && (upper_y || lower_y);
}

void roadfighter::World::attach(std::shared_ptr<roadfighter::ScoreObserver> &score) {
    World::score = score;
}
