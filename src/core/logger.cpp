#include "logger.hpp"

#include <iostream>
#include <cstdarg>

namespace minecraft {
    std::ofstream Logger::logStream;
    bool Logger::isOpen;
    LogLevel Logger::minLogLevel;
    std::mutex Logger::logMutex;

    #define BUF_SIZE 2056

    #define HELPER_DEF_LVL_LOG(LOGLEVEL)    \
        LogLevel lvl = LogLevel::LOGLEVEL;  \
        va_list argptr;                     \
        va_start(argptr, message);          \
                                            \
        Logger::log(lvl, message, argptr);  \
                                            \
        va_end(argptr);                     \

    bool Logger::init(const char* logFilename, LogLevel minLogLevel) {
        Logger::minLogLevel = minLogLevel;

        Logger::logStream.open(logFilename, std::ofstream::out | std::ofstream::app);

        Logger::isOpen = !Logger::logStream.fail();

        return Logger::isOpen;
    }

    void Logger::debug(const char* message, ...) {
        HELPER_DEF_LVL_LOG(DEBUG)
    }

    void Logger::info(const char* message, ...) {
        HELPER_DEF_LVL_LOG(INFO)
    }

    void Logger::warn(const char* message, ...) {
        HELPER_DEF_LVL_LOG(WARN)
    }

    void Logger::error(const char* message, ...) {
        HELPER_DEF_LVL_LOG(ERROR)
    }

    void Logger::setMinLogLevel(LogLevel minLogLevel) {
        Logger::minLogLevel = minLogLevel;
    }

    void Logger::close() {
        if(Logger::logStream.is_open()) {
            Logger::logStream.flush();
            Logger::logStream.close();
        }
    }

    void Logger::log(LogLevel lvl, const char* message, va_list argptr) {
        char buffer[BUF_SIZE];
        size_t bufferLen;
        bool newLineRequired = false;
        
        if(message == nullptr || !Logger::isOpen)
            return;
        
        if(lvl < Logger::minLogLevel)
            return;
        
        std::lock_guard<std::mutex> guard(Logger::logMutex);

        vsnprintf(buffer, BUF_SIZE, message, argptr);
        bufferLen = std::strlen(buffer);
        if(bufferLen > 0 && buffer[bufferLen - 1] != '\n')
            newLineRequired = true;
        
        Logger::logStream << lvl.toLogPrefix() << ": " << buffer;

        if(lvl == LogLevel::ERROR) {
            std::cerr << lvl.getColorCode() << lvl.toLogPrefix() << ": " << buffer
                << "\033[0m";
        } else {
            std::cout << lvl.getColorCode() << lvl.toLogPrefix() << ": " << buffer
                << "\033[0m";
        }

        if(newLineRequired) {
            Logger::logStream << std::endl;
            if(lvl == LogLevel::ERROR)
                std::cerr << std::endl;
            else
                std::cout << std::endl;
        }

        Logger::logStream.flush();
        if(lvl == LogLevel::ERROR)
            std::cerr.flush();
        else
            std::cout.flush();
    }
} // namespace minecraft
