//
// Created by Lander on 03.06.19.
//

#ifndef ROAD_FIGHTER_CONFIGURATION_H
#define ROAD_FIGHTER_CONFIGURATION_H

#include "FileReader.h"
#include <memory>

namespace RoadFighter {
class MissingConfigFile : public ExceptionBase
{
};
class Configuration
{
        static std::shared_ptr<Configuration> m_pConfiguration;

        std::unique_ptr<FileReader> config;

public:
        Configuration();

        static std::shared_ptr<Configuration> Instance();

        unsigned int getWidth() const;

        unsigned int getHeight() const;

        unsigned int getFPS() const;

        unsigned int getMaxSpeed() const;

        unsigned int getMinSpeed() const;

        unsigned int getNormalSpeed() const;

        unsigned int getPassingCarSpeed();

        unsigned int getBulletDelay() const;

        std::string getPath(const std::string& key);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_CONFIGURATION_H
