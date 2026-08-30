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

    std::cout << "Logfile: " << logfile << std::endl;

    std::filesystem::create_directories(
        std::filesystem::path(FSHelper::getAppFolder()));

    Logger::init(logfile.c_str(), LogLevel::INFO);

    // TODO: everything else

    Logger::info("Test log %lli", 123456789Ui64);

    Logger::close();

    return 0;
}
