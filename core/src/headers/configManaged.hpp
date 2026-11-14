#pragma once
#include <string>

struct ConfigManaged
{
    std::string fileName;
    int id;
    virtual const std::string& getFileName() const = 0;
    virtual int getId() const = 0;
    virtual std::string serialize() = 0;
    virtual ~ConfigManaged() = default;
};

