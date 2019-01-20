//
// Created by lander on 18.01.19.
//

#include "ScoreObserver.h"

roadfighter::ScoreObserver::ScoreObserver(const std::shared_ptr<roadfighter::World>& subject) : subject(subject) {}

int roadfighter::ScoreObserver::getScore() const { return score; }

void roadfighter::ScoreObserver::update()
{
        int placementScore = 0;
        for (auto& c : subject->getRaceCars()) {
                // Checks if player is further on screen than other racecars
                if (c->getUpperY() > subject->getPlayer()->getUpperY()) {
                        placementScore += 5000;
                }
        }
        score = subject->getDistance() + placementScore - subject->getA_collisions() * 500;
        score = std::max(score, 0);
}
