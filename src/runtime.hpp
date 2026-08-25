/**
 * @file  runtime.hpp
 * @brief Runtime singleton that provides stuff like the logger, renderer, etc.
 * @since 0.0.1-ALPHA
 * @author ArrODevv
 * @copyright 2026 ArrODevv
 */

#pragma once

#ifndef MINECRAFT_RUNTIME_HPP
#define MINECRAFT_RUNTIME_HPP

#include "core/logger.hpp"

#include <cassert>

namespace minecraft {
    class Runtime {
        public:
            static Runtime& getInstance() {
                return obj;
            }

            Logger& getLogger() {
                assert(initialized == true);
                return logger;
            }

        private:
            static bool initialized;
            static Logger logger;
            static Runtime obj; // instance
            Runtime() {
                initialized = true;
                logger = Logger(); // TODO: log file
            }
    }; // class Runtime
} // namespace minecraft

#endif // !MINECRAFT_RUNTIME_HPP
