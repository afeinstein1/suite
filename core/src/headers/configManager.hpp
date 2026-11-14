#pragma once

#include <map>
#include "config.hpp"

struct ConfigManager
{
    std::map<int, ConfigManaged> configs;

};
