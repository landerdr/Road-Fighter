//
// Created by LanderDeRoeck on 08/08/2019.
//

#ifndef ROAD_FIGHTER_FILEREADER_H
#define ROAD_FIGHTER_FILEREADER_H

#include "ExceptionBase.hpp"
#include <map>
#include <string>
#include <vector>

namespace RoadFighter {
// Thrown when key isn't found in the file
class KeyNotFound : public ExceptionBase
{
        const char* what() const noexcept { return "Invalid key requested, please check config file\n"; }
};
// Thrown when an incorrect type is requested
class IncorrectKeyType : public ExceptionBase
{
        const char* what() const noexcept { return "Incorrect key type requested, please check config file\n"; }
};

class FileReader
{
protected:
        /*
         * Map for data from file
         * Key:Value gets mapped to <Key, Value>
         */
        std::map<std::string, std::string> data;

        /*
         * Code used to split string into components
         * code from: https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
         */
        static std::vector<std::string> splitString(const std::string& str, char delimiter);

public:
        /**
         * Reads data from fileName and loads into internal variable
         * @param fileName
         */
        explicit FileReader(const std::string& fileName);
        /**
         * Checks if data is empty
         * @return
         */
        bool hasData() { return !data.empty(); };
        /**
         * Gets int type value from key
         * @param key
         * @return
         */
        int getInt(const std::string& key);
        /**
         * Gets bool type value from key
         * @param key
         * @return
         */
        bool getBool(const std::string& key);
        /**
         * Gets string type value from key
         * @param key
         * @return
         */
        std::string getString(const std::string& key);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_FILEREADER_H
