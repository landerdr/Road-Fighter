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
    static Random* Instance();

private:
    static Random* m_pRandom;
};


#endif //ROAD_FIGHTER_RANDOM_H
