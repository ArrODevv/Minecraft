#pragma once

#ifndef MINECRAFT_FS_HPP
#define MINECRAFT_FS_HPP

#include "common.hpp"

#include <string>

namespace minecraft {
    class FSHelper {
        public:
            static std::string getMainDrivePath();
            static char getPathSep();
            static std::string getAppFolder();
    }; // class FSHelper
} // namespace minecraft

#endif // !MINECRAFT_FS_HPP
