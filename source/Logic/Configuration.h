//
// Created by Lander on 03.06.19.
//

#ifndef ROAD_FIGHTER_CONFIGURATION_H
#define ROAD_FIGHTER_CONFIGURATION_H

#include "FileReader.h"
#include <memory>

namespace RoadFighter {
// Exception for
class MissingConfigFile : public ExceptionBase
{
        const char* what() const noexcept { return "Config file not found\n"; }
};
class Configuration
{
        static std::shared_ptr<Configuration> m_pConfiguration;

        std::unique_ptr<FileReader> config;

protected:
        Configuration();

public:
        /**
         * Instance for singleton
         * @return
         */
        static std::shared_ptr<Configuration> Instance();

        /**
         * Returns screen width
         * @return
         */
        unsigned int getWidth() const;
        /**
         * Returns screen height
         * @return
         */
        unsigned int getHeight() const;
        /**
         * Returns target FPS
         * @return
         */
        unsigned int getFPS() const;
        /**
         * Returns Entity max speed
         * @return
         */
        unsigned int getMaxSpeed() const;
        /**
         * Returns Entity min speed
         * @return
         */
        unsigned int getMinSpeed() const;
        /**
         * Returns Entity normal speed
         * @return
         */
        unsigned int getNormalSpeed() const;
        /**
         * Returns speed at which passing cars travel
         * @return
         */
        unsigned int getPassingCarSpeed();
        /**
         * Returns Bullet shot delay
         * @return
         */
        unsigned int getBulletDelay() const;
        /**
         * Returns Bullet speed
         * @return
         */
        unsigned int getBulletSpeed() const;
        /**
         * Gets path to key
         * @param key
         * @return
         */
        std::string getPath(const std::string& key);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_CONFIGURATION_H
