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
                        if (line == "Highscore:") {
                                getline(myfile, line);
                                highscore = std::stoi(line);
                                std::cout << highscore;
                                continue;
                        }

                        // Does nothing if variable doen't match
                        getline(myfile, line);
                }

                myfile.close();
        }

        else {
                std::ofstream outfile(savefile);
                outfile << "Name:\n\nHighscore:\n0";
                outfile.close();
        }
}

int roadfighter::HighSoreModule::getHighscore() const { return highscore; }

void roadfighter::HighSoreModule::save(int score)
{
        if (score > highscore) {
                std::ofstream outfile(savefile);

                outfile << "Name:\n\nHighscore:\n" << score;

                outfile.close();
        }
}
