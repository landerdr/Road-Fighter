//
// Created by vyolex on 16.03.19.
//

#ifndef ROAD_FIGHTER_HIGHSOREMODULE_H
#define ROAD_FIGHTER_HIGHSOREMODULE_H


#include <string>

namespace roadfighter {
    class HighSoreModule {
        std::string savefile = "./Resources/save";
        int highscore = 0;

    public:
        HighSoreModule();

        int getHighscore() const;

        void save(int score);
    };
}



#endif //ROAD_FIGHTER_HIGHSOREMODULE_H
