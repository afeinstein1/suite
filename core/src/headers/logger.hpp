#pragma once

#include <iostream>

namespace Logger
{
    std::ostream& info(std::ostream& msg);
    std::ostream& warn(std::ostream& msg);
    std::ostream& error(std::ostream& msg);
    std::ostream& fatal(std::ostream& msg);
    std::ostream& debug(std::ostream& msg);

}