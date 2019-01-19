//
// Created by lander on 18.01.19.
//

#include "ScoreObserver.h"

roadfighter::ScoreObserver::ScoreObserver(const std::shared_ptr<roadfighter::World> &subject) : subject(subject) {}

int roadfighter::ScoreObserver::getScore() const {
    return score;
}

void roadfighter::ScoreObserver::update() {
    score += 1;
}
