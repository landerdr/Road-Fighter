//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H


class Random {
protected:
    Random();
public:
    virtual ~Random();
    static std::shared_ptr<Random> Instance();

private:
    static std::shared_ptr<Random> m_pRandom;
};


#endif //ROAD_FIGHTER_RANDOM_H
