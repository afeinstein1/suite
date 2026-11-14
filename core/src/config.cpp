#include "headers/config.hpp"


std::string Config::serialize()
{
    return "\n{\n"
           "\t\"id\": " + std::to_string(id) + ",\n"
           "\t\"appName\": \"" + appName + "\",\n"
           "\t\"debugEnabled\": " + (debugEnabled ? "true" : "false") + ",\n"
           "\t\"theme\": " + std::to_string(static_cast<int>(theme)) + ",\n"
           "\t\"logLevel\": " + std::to_string(static_cast<int>(logLevel)) + "\n"
           "}";
}