#include "headers/configManager.hpp"
#include <fstream>
#include "headers/logger.hpp"

void ConfigManager::addConfig(std::unique_ptr<ConfigManaged> config)
{
    configs[config->getId()] = std::move(config);
}

void ConfigManager::writeConfigs()
{
    for (const auto& [id, config] : configs)
    {
        std::string serialized = config->serialize();
        std::cout << "suite/configs/" + config->getFileName() << std::endl;
        std::ofstream file("configs/" + config->getFileName());
        if (file.is_open())
        {
            file << serialized;
            file.close();
        }
        Logger::info(std::cout) << "Wrote configuration to " << config->getFileName() << std::endl;
    }

    Logger::info(std::cout) << "All configurations have been written." << std::endl;
}
