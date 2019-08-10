//
// Created by lander on 12/10/18.
//

#include "World.h"
#include "Random.h"
#include <tuple>

std::tuple<bool, bool> RoadFighter::World::entityCollision(const std::shared_ptr<RoadFighter::Entity>& ent1,
                                                           const std::shared_ptr<RoadFighter::Entity>& ent2)
{
        if (ent1 == ent2)
                return {false, false};
        bool left_x = ent1->getLeftX() >= ent2->getLeftX() && ent1->getLeftX() <= ent2->getRightX();
        bool right_x = ent1->getRightX() >= ent2->getLeftX() && ent1->getRightX() <= ent2->getRightX();
        bool upper_y = ent1->getUpperY() <= ent2->getUpperY() && ent1->getUpperY() >= ent2->getLowerY();
        bool lower_y = ent1->getLowerY() <= ent2->getUpperY() && ent1->getLowerY() >= ent2->getLowerY();
        return {left_x && (upper_y || lower_y), right_x && (upper_y || lower_y)};
}

void RoadFighter::World::attach(std::shared_ptr<RoadFighter::ScoreObserver>& score) { World::score = score; }

int RoadFighter::World::getDistance() const { return distance; }

int RoadFighter::World::getFinish() const { return finish; }

int RoadFighter::World::getSpeed() const { return speed; }

const std::shared_ptr<RoadFighter::PlayerCar>& RoadFighter::World::getPlayer() const { return Player; }

const std::set<std::shared_ptr<RoadFighter::RacingCar>>& RoadFighter::World::getRaceCars() const { return RaceCars; }

void RoadFighter::World::run()
{
        // Player passed finish
        if (distance > finish) {
                speed = 0;
                return;
        }
        randomEvent();
        // Handle keyboard input
        if (speed < 400 && (!S || speed < 200)) {
                speed += 1;
        }
        if (speed < 600 && Z) {
                speed += 1;
        }
        if (speed > 400 && (!Z || speed > 600)) {
                speed -= 1;
        }
        if (speed > 200 && S) {
                speed -= 1;
        }
        if (!Bullet && Space && shot + std::chrono::seconds(1) < std::chrono::steady_clock::now()) {
                Bullet = factory->createBullet(Player->getC_x(), Player->getUpperY());
                shot = std::chrono::steady_clock::now();
        }
        Player->setM_right(D);
        Player->setM_left(Q);
        Player->setPlayerspeed(speed);
        clearInput();

        // Run Entities
        Player->run();

        for (auto it = PassingCars.begin(); it != PassingCars.end();) {
                (*it)->run(speed);
                if ((*it)->getUpperY() > 4) {
                        it = PassingCars.erase(it);
                } else {
                        ++it;
                }
        }
        for (auto& e : RaceCars) {
                e->run(speed);
        }
        if (Bullet) {
                Bullet->run();
                if (Bullet->getLowerY() < -4) {
                        Bullet = nullptr;
                }
        }

        // Entity collision detection & handling

        // Passing cars detection
        for (auto it = PassingCars.begin(); it != PassingCars.end();) {
                std::tuple<bool, bool> collision;
                bool removed = false;
                if (Bullet) {
                        collision = entityCollision(Bullet, *it);
                        if (std::get<0>(collision) || std::get<1>(collision)) {
                                Bullet = nullptr;
                                it = PassingCars.erase(it);
                                removed = true;
                        }
                }
                if (!removed) {
                        collision = entityCollision(Player, *it);
                        if (std::get<0>(collision) || std::get<1>(collision)) {
                                if ((*it)->getType() == Speed) {
                                        speed = std::max(0, speed + 200);
                                } else {
                                        speed = std::max(0, speed - 200);
                                        a_collisions += 1;
                                }
                                it = PassingCars.erase(it);
                                removed = true;
                        }
                }
                if (!removed) {
                        for (auto& e : RaceCars) {
                                collision = entityCollision(e, *it);
                                if (std::get<0>(collision) || std::get<1>(collision)) {
                                        if ((*it)->getType() == Speed) {
                                                e->slow(-200);
                                        } else {
                                                e->slow(200);
                                        }
                                        it = PassingCars.erase(it);
                                        removed = true;
                                        break;
                                }
                        }
                }
                if (!removed) {
                        ++it;
                }
        }

        for (auto& e : RaceCars) {
                std::tuple<bool, bool> collision = entityCollision(Player, e);
                if (std::get<0>(collision)) {
                        Player->moveright();
                        Player->moveright();
                        speed = std::max(0, speed - 50);
                        e->moveleft();
                        e->moveleft();
                        e->slow(50);
                } else if (std::get<1>(collision)) {
                        Player->moveleft();
                        Player->moveleft();
                        speed = std::max(0, speed - 50);
                        e->moveright();
                        e->moveright();
                        e->slow(50);
                }
                for (auto& e2 : RaceCars) {
                        collision = entityCollision(e, e2);
                        if (std::get<0>(collision)) {
                                e->moveright();
                                e->moveright();
                                e->slow(20);
                                e2->moveleft();
                                e2->moveleft();
                                e2->slow(20);
                        } else if (std::get<1>(collision)) {
                                e->moveleft();
                                e->moveleft();
                                e->slow(20);
                                e2->moveright();
                                e2->moveright();
                                e2->slow(20);
                        }
                }
                if (Bullet) {
                        collision = entityCollision(Bullet, e);
                        if (std::get<0>(collision) || std::get<1>(collision)) {
                                Bullet = nullptr;
                                e->slow(100);
                        }
                }
        }

        score->update();
}

void RoadFighter::World::randomEvent()
{
        int event = RoadFighter::Random::Instance()->getInt() % 5000;
        if (event < 10) {
                double x = -1.5 + 0.001 * (RoadFighter::Random::Instance()->getInt() % 2000);
                x = std::min(std::max(x, -1.3), 0.3);
                PassingCars.emplace(factory->createPassingCar(static_cast<float>(x), -4, RoadFighter::Slow));
        } else if (event < 15) {
                double x = -1.5 + 0.001 * (RoadFighter::Random::Instance()->getInt() % 2000);
                x = std::min(std::max(x, -1.3), 0.3);
                PassingCars.emplace(factory->createPassingCar(static_cast<float>(x), -4, RoadFighter::Speed));
        }
}

void RoadFighter::World::clearInput()
{
        Z = false;
        Q = false;
        S = false;
        D = false;
        Space = false;
}

unsigned int RoadFighter::World::getA_collisions() const { return a_collisions; }

int RoadFighter::World::getScore() { return score->getScore(); }
