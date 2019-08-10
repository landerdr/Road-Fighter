//
// Created by Lander on 03.06.19.
//

#ifndef ROAD_FIGHTER_CONFIGURATION_H
#define ROAD_FIGHTER_CONFIGURATION_H

#include "FileReader.h"
#include <memory>

namespace RoadFighter {
class Configuration
{
        static std::shared_ptr<Configuration> m_pConfiguration;

        std::unique_ptr<FileReader> config;

        static void createConfigFile();

public:
        Configuration();

        static std::shared_ptr<Configuration> Instance();

        unsigned int getWidth() const;

        unsigned int getHeight() const;

        unsigned int getFPS() const;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_CONFIGURATION_H
