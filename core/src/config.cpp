#include "headers/config.hpp"
#include "libraries/rapidjson/document.h"
#include "headers/logger.hpp"



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
void Config::deserialize(const std::string& json)
{

    try 
    {
        rapidjson::Document doc;
        doc.Parse(json.c_str());
        if (doc.HasParseError()) {
            throw std::runtime_error("Error parsing JSON");
        }
        if (doc.HasMember("id")) {
            if (!doc["id"].IsInt()) {
                Logger::error(std::cout) << "'id' must be an integer" << std::endl;
                Logger::warn(std::cout) << "Using default value for 'id'." << std::endl;
                Logger::info(std::cout) << "continuing to parse JSON" << std::endl;
                id = 1;
            }
            else
            {
                id = doc["id"].GetInt();
            }
        
        }
        if (doc.HasMember("appName")) {
            appName = doc["appName"].GetString();
        }
        if (doc.HasMember("debugEnabled")) {
            if (!doc["debugEnabled"].IsBool()) {
                Logger::error(std::cout) << "'debugEnabled' must be a boolean" << std::endl;
                Logger::warn(std::cout) << "Using default value for 'debugEnabled'." << std::endl;
                Logger::info(std::cout) << "continuing to parse JSON" << std::endl;
                debugEnabled = false;
            }
            else
            {
                debugEnabled = doc["debugEnabled"].GetBool();
            }
        }
        if (doc.HasMember("theme")) {
            if (!doc["theme"].IsInt()) {
                Logger::error(std::cout) << "'theme' must be an integer" << std::endl;
                Logger::warn(std::cout) << "Using default value for 'theme'." << std::endl;
                Logger::info(std::cout) << "continuing to parse JSON" << std::endl;
                theme = Theme::Light;
            }
            else
            {
                theme = static_cast<Theme>(doc["theme"].GetInt());
            }
        }
        
        if (doc.HasMember("logLevel")) {
            if (!doc["logLevel"].IsInt()) {
                Logger::error(std::cout) << "'logLevel' must be an integer" << std::endl;
                Logger::warn(std::cout) << "Using default value for 'logLevel'." << std::endl;
                Logger::info(std::cout) << "continuing to parse JSON" << std::endl;
                logLevel = LogLevel::Info;
            }
            else
            {
                logLevel = static_cast<LogLevel>(doc["logLevel"].GetInt());
            }
        }
        

    }
    catch (const std::runtime_error& e)
    {
        Logger::error(std::cout) << "File is unparsable: default values will be used while the application runs." << std::endl;
        Logger::warn(std::cout) << "Default values will be used while the application runs." << std::endl;
        Logger::warn(std::cout) << "Update the configuration file to correct the errors or defaults will be saved." << std::endl;
    }
    catch (...)
    {
        Logger::fatal(std::cout) << "Unknown error occurred while deserializing configuration." << std::endl;
        Logger::warn(std::cout) << "Default values will be used while the application runs." << std::endl;
        Logger::warn(std::cout) << "Default values will be saved immediately to prevent this error from recurring." << std::endl;
    }

}