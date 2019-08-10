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
class KeyNotFound : public ExceptionBase
{
};

class IncorrectKeyType : public ExceptionBase
{
};

class FileReader
{
protected:
        std::map<std::string, std::string> data;

        static std::vector<std::string> splitString(const std::string& str, char delimiter);

public:
        explicit FileReader(const std::string& fileName);

        bool hasData() { return !data.empty(); };

        int getInt(const std::string& key);

        bool getBool(const std::string& key);

        std::string getString(const std::string& key);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_FILEREADER_H
