//
// Created by LanderDeRoeck on 08/08/2019.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

RoadFighter::FileReader::FileReader(const std::string& fileName)
{
        std::string line;
        std::string lastline;
        std::vector<std::string> internal;
        std::ifstream readFile(fileName);
        if (readFile.is_open()) {
                for (int i = 0; i < 500; i++) {
                        lastline = line;

                        // Scans variable name
                        getline(readFile, line);

                        if (lastline == line) {
                                break;
                        }

                        internal = splitString(line, ':');

                        if (internal.size() != 2) {
                                continue;
                        }

                        data.insert(std::pair<std::string, std::string>(internal[0], internal[1]));

                        std::cout << line << std::endl;
                }

                readFile.close();
        }
}

/*
 * code from: https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
 */
std::vector<std::string> RoadFighter::FileReader::splitString(const std::string& str, char delimiter)
{
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;

        while (getline(ss, tok, delimiter)) {
                internal.push_back(tok);
        }

        return internal;
}

int RoadFighter::FileReader::getInt(const std::string& key)
{
        auto it = data.find(key);

        if (it == data.end())
                throw KeyNotFound();

        try {
                return std::stoi(it->second);
        } catch (const std::exception&) {
                throw IncorrectKeyType();
        }
}
std::string RoadFighter::FileReader::getString(const std::string& key)
{
        auto it = data.find(key);

        if (it == data.end())
                throw KeyNotFound();

        return it->second;
}
