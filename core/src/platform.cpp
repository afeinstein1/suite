#include "headers/platform.hpp"
#include "headers/logger.hpp"
#include "headers/config.hpp"
#include "headers/configManager.hpp"


namespace Platform
{
    void initialize()
    {
        Logger::info(std::cout) << "Platform initialization started!" << std::endl;

        Logger::info(std::cout) << "Loading configuration..." << std::endl;
        Config config;
        Logger::info(std::cout) << config.serialize() << std::endl;
        Logger::info(std::cout) << "Configuration loaded successfully!" << std::endl;

        Logger::info(std::cout) << "Running temporary development tests..." << std::endl;
        devTests();
        Logger::info(std::cout) << "Development tests finished!" << std::endl;

        Logger::info(std::cout) << "Platform initialized!" << std::endl;
    }

    void devTests()
    {
        Config config;
        ConfigManager configManager;
        configManager.addConfig(std::make_unique<Config>(config));
        configManager.writeConfigs();
    }
}