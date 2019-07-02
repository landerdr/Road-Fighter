//
// Created by vyolex on 16.03.19.
//

#ifndef ROAD_FIGHTER_HIGHSOREMODULE_H
#define ROAD_FIGHTER_HIGHSOREMODULE_H

#include <string>

namespace roadfighter {
class HighSoreModule
{
        std::string savefile = "./Resources/save";
        int highscore = 0;
        unsigned int width = 600;
        unsigned int height = 800;

public:
        HighSoreModule();

        int getHighscore() const;

        unsigned int getWidth() const;

        unsigned int getHeight() const;

		void save(int score);
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_HIGHSOREMODULE_H
