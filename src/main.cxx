#include <iostream>
#include <sstream>
#include <filesystem>

#include "core/logger.hpp"
#include "core/fs.hpp"

// temp
#include "math/vector2.hpp"

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

    // temp
    math::Vector2 vec {12.34f, 56.78f};
    std::cout << "iostream: \"" << vec << "\"" << std::endl;

    Logger::warn("Logger::warn: \"%s\"", vec.toString().c_str());

    math::Vector2 vec_2 {1.f, 1.f};
    Logger::debug("Vector2(12.34f, 56.78f) + Vector2(1.f, 1.f) = %s", (vec + vec_2).toString().c_str());

    Logger::debug("len of vec1: %f", vec.length());

    Logger::close();

    return 0;
}
