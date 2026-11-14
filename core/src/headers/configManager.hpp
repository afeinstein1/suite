#pragma once

#include <map>

#include <memory>
#include "configManaged.hpp"

struct ConfigManager
{
    std::map<decltype(ConfigManaged::id), std::unique_ptr<ConfigManaged>> configs;

    void addConfig(std::unique_ptr<ConfigManaged> config);
    void writeConfigs();

};
