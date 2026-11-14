#include "headers/platform.hpp"
#include "headers/logger.hpp"


namespace Platform
{
    void initialize()
    {
        Logger::info(std::cout) << "Platform initialization started!" << std::endl;
        Logger::info(std::cout) << "Platform initialized!" << std::endl;
    }
}