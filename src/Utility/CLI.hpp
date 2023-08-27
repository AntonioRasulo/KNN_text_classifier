#pragma once

#include <string>

namespace utility {

    std::string checkAndGetCmdOption(char** begin, char** end, const std::string& option);

}
