#pragma once
#include <string>
#include "ConfigTypes.hpp"
#include "configManaged.hpp"

struct Config: public ConfigManaged
{
    int id = 1;
    std::string appName = "DefaultAppName";
    bool debugEnabled = false;
    Theme theme = Theme::Light;
    LogLevel logLevel = LogLevel::Info;


};