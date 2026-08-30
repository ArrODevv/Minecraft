/**
 * @file logger.hpp
 * @brief Logger implementation for ArrODevv/Minecraft.
 * @since 0.0.1-ALPHA
 * @author ArrODevv
 * @copyright 2026 ArrODevv
 */

#pragma once

#ifndef MINECRAFT_LOGGER_HPP
#define MINECRAFT_LOGGER_HPP

#include "common.hpp"

#include <string>
#include <fstream>
#include <mutex>

/**
 * @brief Top level namespace.
 */
namespace minecraft {
    class LogLevel {
    public:
        enum Value : uint8_t {
            DEBUG,
            INFO,
            WARN,
            ERROR,
        }; // enum Value

        LogLevel() = default;
        constexpr LogLevel(Value level) : value(level) {}

        // Allow switch and comparisons.
        constexpr operator Value() const { return value; }

        explicit operator bool() const = delete;

        constexpr std::string toString() const {
            switch(value) {
                case DEBUG:
                    return "DEBUG";
                case INFO:
                    return "INFO";
                case WARN:
                    return "WARN";
                case ERROR:
                    return "ERROR";
                default:
                    return "INFO";
            }
        }

        constexpr std::string toLogPrefix() const {
            switch(value) {
                case DEBUG:
                    return "[DEBUG]";
                case INFO:
                    return "[INFO] ";
                case WARN:
                    return "[WARN] ";
                case ERROR:
                    return "[ERROR]";
                default:
                    return "[INFO] ";
            }
        }

        constexpr std::string getColorCode() const {
            switch(value) {
                case DEBUG:
                    return "\033[35m";
                case INFO:
                    return "\033[32m";
                case WARN:
                    return "\033[33m";
                case ERROR:
                    return "\033[31m";
                default:
                    return "\033[32m";
            }
        }

    private:
        Value value;
    }; // class LogLevel

    /**
     * @brief Simple and thread-safe logger implementation.
     * @since 0.0.1-ALPHA
     * @author ArrODevv
     * @copyright 2026 ArrODevv
     */
    class Logger {
        public:
            static bool init(const char* logFilename, LogLevel minLogLevel);

            static void debug(const char* message, ...);

            static void info(const char* message, ...);

            static void warn(const char* message, ...);

            static void error(const char* message, ...);

            static void setMinLogLevel(LogLevel minLogLevel);

            static void close();

        private:
            static std::ofstream logStream;
            static bool isOpen;
            static LogLevel minLogLevel;
            static std::mutex logMutex;

            static void log(LogLevel lvl, const char* message, va_list argptr);
    }; // class Logger
}

#endif // !MINECRAFT_LOGGER_HPP
