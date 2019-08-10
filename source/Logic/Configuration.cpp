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
                createConfigFile();
                config = std::make_unique<FileReader>(FileReader("./Resources/config"));
        }
}

unsigned int RoadFighter::Configuration::getWidth() const { return static_cast<unsigned int>(config->getInt("Width")); }

unsigned int RoadFighter::Configuration::getHeight() const
{
        return static_cast<unsigned int>(config->getInt("Height"));
}

unsigned int RoadFighter::Configuration::getFPS() const { return static_cast<unsigned int>(config->getInt("FPS")); }

void RoadFighter::Configuration::createConfigFile()
{
        std::ofstream outfile("./Resources/config");
        outfile << "Width:800\nHeight:600\nFPS:100";
        outfile.close();
}
