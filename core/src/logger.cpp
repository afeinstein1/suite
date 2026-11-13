#include "headers/logger.hpp"
#include <iostream>


namespace Logger
{
    std::ostream& info(std::ostream& msg) 
    {
         return msg << "\033[32m[INFO] \033[0m";
    }

    std::ostream& warn(std::ostream& msg) 
    { 
        return msg << "\033[33m[WARN] \033[0m";
    }

    std::ostream& error(std::ostream& msg) 
    { 
        return msg << "\033[31m[ERROR] \033[0m"; 
    }

    std::ostream& fatal(std::ostream& msg) 
    { 
        return msg << "\033[35m[FATAL] \033[0m"; 
    }

    std::ostream& debug(std::ostream& msg) 
    { 
        return msg << "\033[36m[DEBUG] \033[0m";
    }
}