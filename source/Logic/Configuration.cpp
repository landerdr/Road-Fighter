//
// Created by Lander on 03.06.19.
//

#include "Configuration.h"
#include <fstream>
#include <iostream>

roadfighter::Configuration::Configuration()
{
        config = std::make_unique<FileReader>(FileReader("./Resources/config"));

        if (!config->hasData()) {
                std::ofstream outfile("./Resources/config");
                outfile << "Width:800\nHeight:600";
                outfile.close();
                config = std::make_unique<FileReader>(FileReader("./Resources/config"));
        }
}

unsigned int roadfighter::Configuration::getWidth() const { return static_cast<unsigned int>(config->getInt("Width")); }

unsigned int roadfighter::Configuration::getHeight() const { return static_cast<unsigned int>(config->getInt("Height")); }