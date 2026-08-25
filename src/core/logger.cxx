#include "logger.hpp"

#include <iostream>

namespace minecraft {
    Logger::Logger() {
        
    }

    void Logger::testLog() {
        std::cout << "Test log message" << std::endl;
    }
}
