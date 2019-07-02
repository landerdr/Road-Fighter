//
// Created by vyolex on 16.03.19.
//

#include "HighSoreModule.h"
#include <fstream>
#include <iostream>

roadfighter::HighSoreModule::HighSoreModule()
{
        std::string line;
        std::ifstream myfile(savefile);
        if (myfile.is_open()) {
                for (int i = 0; i < 4; i++) {
                        // Scans variable name
                        getline(myfile, line);
                        std::cout << line << " ";
                        if (line == "Highscore:") {
                                getline(myfile, line);
                                highscore = std::stoi(line);
                                std::cout << line << std::endl;
                                continue;
                        }
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
                outfile << "Name:\n\nHighscore:\n0\nWidth:\n800\nHeight:\n600";
                outfile.close();
        }
}

int roadfighter::HighSoreModule::getHighscore() const { return highscore; }

unsigned int roadfighter::HighSoreModule::getWidth() const { return width; }

unsigned int roadfighter::HighSoreModule::getHeight() const { return height; }

void roadfighter::HighSoreModule::save(int score)
{
        if (score > highscore) {
                std::ofstream outfile(savefile);

                outfile << "Name:\n\nHighscore:\n" << score << "\nWidth:\n" << width << "\nHeight:\n" << height;

                outfile.close();
        }
}
