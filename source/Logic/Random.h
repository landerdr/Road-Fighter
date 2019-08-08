//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H

#include <memory>

namespace roadfighter {
class Random
{
protected:
        Random();

public:
        static std::shared_ptr<Random> Instance();

        /**
         * Returns random int value
         * @return
         */
        static int getInt();

private:
        static std::shared_ptr<Random> m_pRandom;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_RANDOM_H
