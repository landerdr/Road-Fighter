//
// Created by Lander on 16.03.19.
//

#ifndef ROAD_FIGHTER_HIGHSOREMODULE_H
#define ROAD_FIGHTER_HIGHSOREMODULE_H

#include "FileReader.h"
#include <memory>
#include <string>

namespace RoadFighter {
class HighSoreModule
{
        std::unique_ptr<FileReader> file;
        int highscore = 0;

public:
        HighSoreModule();

        int getHighscore() const;

        void save(int score);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_HIGHSOREMODULE_H
