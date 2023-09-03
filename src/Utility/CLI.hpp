#ifndef CLI_H
#define CLI_H

#include <string>

namespace utility {

    std::string checkAndGetCmdOption(char** begin, char** end, const std::string& option);

}

#endif
