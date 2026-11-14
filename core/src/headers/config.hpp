#pragma once
#include <string>
#include "ConfigTypes.hpp"
#include "configManaged.hpp"

struct Config: public ConfigManaged
{
    std::string fileName = "config.json";
    int id = 1;
    std::string appName = "DefaultAppName";
    bool debugEnabled = false;
    Theme theme = Theme::Light;
    LogLevel logLevel = LogLevel::Info;

    const std::string& getFileName() const override { return fileName; }
    int getId() const override { return id; }
    std::string serialize() override;


};