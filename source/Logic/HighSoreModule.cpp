//
// Created by Lander on 16.03.19.
//

#include "HighSoreModule.h"
#include <fstream>

roadfighter::HighSoreModule::HighSoreModule()
{
        file = std::make_unique<FileReader>(FileReader("./Resources/save"));

        if (file->hasData()) {
                highscore = file->getInt("Highscore");
        }
}

int roadfighter::HighSoreModule::getHighscore() const { return highscore; }

void roadfighter::HighSoreModule::save(int score)
{
        if (score > highscore) {
                std::ofstream outfile("./Resources/save");

                outfile << "Name:\nHighscore:" << score;

                outfile.close();
        }
}
