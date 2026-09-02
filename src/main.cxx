#include <iostream>
#include <sstream>
#include <filesystem>

#include "core/logger.hpp"
#include "core/fs.hpp"

using namespace minecraft;

int main(int argc, char** argv) {
    std::string logfile;
    std::stringstream ss;

    ss << FSHelper::getAppFolder() << "log.latest";
    logfile = ss.str();

    std::filesystem::create_directories(
        std::filesystem::path(FSHelper::getAppFolder()));

    LogLevel minLogLevel = LogLevel::INFO;

#if _DEBUG
    minLogLevel = LogLevel::DEBUG;
#endif

    Logger::init(logfile.c_str(), minLogLevel);

    // TODO: everything else

    

    Logger::close();

    return 0;
}
