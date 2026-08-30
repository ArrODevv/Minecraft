#include <iostream>

#include "core/logger.hpp"

using namespace minecraft;

int main(int argc, char** argv) {
    Logger::init("./log.latest", LogLevel::INFO);

    // TODO: everything else

    Logger::close();

    return 0;
}
