#include "headers/configManager.hpp"
#include <fstream>
#include "headers/logger.hpp"

void ConfigManager::addConfig(std::unique_ptr<ConfigManaged> config)
{
    configs[config->getId()] = std::move(config);
}

void ConfigManager::writeConfigs()
{
    try
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
    catch (const std::exception& e)
    {
        Logger::error(std::cout) << "Error writing configurations: " << e.what() << std::endl;
    }
}
void ConfigManager::pullConfigs()
{   
    try
    {   
        for (const auto& [id, config] : configs)
        {
            std::ifstream file("configs/" + config->getFileName());
            if (file.is_open())
            {
                std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                config->deserialize(json);
                file.close();
                Logger::info(std::cout) << "Loaded configuration from " << config->getFileName() << std::endl;
            }
            else
            {
                Logger::error(std::cout) << "Configuration file not found for " << config->getFileName() << std::endl;\
                Logger::warn(std::cout) << "This configuration will be set to default values." << std::endl;
            }
            
        }

        Logger::info(std::cout) << "All configurations have been loaded." << std::endl;
    }
    catch (const std::exception& e)
    {
        Logger::error(std::cout) << "Error pulling configurations: " << e.what() << std::endl;
    }
}