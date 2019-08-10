//
// Created by Lander on 03.06.19.
//

#include "Configuration.h"
#include <fstream>

std::shared_ptr<RoadFighter::Configuration> RoadFighter::Configuration::m_pConfiguration = nullptr;

std::shared_ptr<RoadFighter::Configuration> RoadFighter::Configuration::Instance()
{
        if (m_pConfiguration == nullptr) {
                m_pConfiguration = std::make_shared<RoadFighter::Configuration>();
        }
        return m_pConfiguration;
}

RoadFighter::Configuration::Configuration()
{
        config = std::make_unique<FileReader>(FileReader("./Resources/config"));

        if (!config->hasData()) {
                throw MissingConfigFile();
        }
}

unsigned int RoadFighter::Configuration::getWidth() const { return static_cast<unsigned int>(config->getInt("Width")); }

unsigned int RoadFighter::Configuration::getHeight() const
{
        return static_cast<unsigned int>(config->getInt("Height"));
}

unsigned int RoadFighter::Configuration::getFPS() const { return static_cast<unsigned int>(config->getInt("FPS")); }

std::string RoadFighter::Configuration::getPath(const std::string& key) { return config->getString(key); }

unsigned int RoadFighter::Configuration::getMaxSpeed() const
{
        return static_cast<unsigned int>(config->getInt("Max Speed"));
}
unsigned int RoadFighter::Configuration::getMinSpeed() const
{
        return static_cast<unsigned int>(config->getInt("Min Speed"));
}
unsigned int RoadFighter::Configuration::getNormalSpeed() const
{
        return static_cast<unsigned int>(config->getInt("Normal Speed"));
}
unsigned int RoadFighter::Configuration::getPassingCarSpeed()
{
        return static_cast<unsigned int>(config->getInt("PassingCar Speed"));
}
unsigned int RoadFighter::Configuration::getBulletDelay() const
{
        return static_cast<unsigned int>(config->getInt("Bullet Delay"));
}
unsigned int RoadFighter::Configuration::getBulletSpeed() const
{
        return static_cast<unsigned int>(config->getInt("Bullet Speed"));
}
