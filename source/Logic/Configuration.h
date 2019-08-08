//
// Created by Lander on 03.06.19.
//

#ifndef ROAD_FIGHTER_CONFIGURATION_H
#define ROAD_FIGHTER_CONFIGURATION_H

#include "FileReader.h"
#include <memory>

namespace roadfighter {
class Configuration
{
        std::unique_ptr<FileReader> config;

        static void createConfigFile();
public:
        Configuration();

        unsigned int getWidth() const;

        unsigned int getHeight() const;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_CONFIGURATION_H
