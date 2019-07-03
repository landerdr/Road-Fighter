//
// Created by Lander on 03.06.19.
//

#include "Configuration.h"
#include <fstream>
#include <iostream>

roadfighter::Configuration::Configuration()
{
        std::string line;
        std::ifstream myfile(savefile);
        if (myfile.is_open()) {
                for (int i = 0; i < 4; i++) {
                        // Scans variable name
                        getline(myfile, line);
                        std::cout << line << " ";
                        if (line == "Width:") {
                                getline(myfile, line);
                                width = (unsigned)std::stoi(line);
                                std::cout << line << std::endl;
                                continue;
                        }
                        if (line == "Height:") {
                                getline(myfile, line);
                                height = (unsigned)std::stoi(line);
                                std::cout << line << std::endl;
                                continue;
                        }

                        // Does nothing if variable doen't match
                        getline(myfile, line);
                        std::cout << line << std::endl;
                }

                myfile.close();
        }

        else {
                std::ofstream outfile(savefile);
                outfile << "Width:\n800\nHeight:\n600";
                outfile.close();
        }
}

unsigned int roadfighter::Configuration::getWidth() const { return width; }

unsigned int roadfighter::Configuration::getHeight() const { return height; }