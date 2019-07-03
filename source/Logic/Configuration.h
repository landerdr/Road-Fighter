//
// Created by Lander on 03.06.19.
//

#ifndef ROAD_FIGHTER_CONFIGURATION_H
#define ROAD_FIGHTER_CONFIGURATION_H

#include <string>

namespace roadfighter {
class Configuration
{
        std::string savefile = "./Resources/config";
        unsigned int width = 800;
        unsigned int height = 600;

public:
        Configuration();

        unsigned int getWidth() const;

        unsigned int getHeight() const;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_CONFIGURATION_H
