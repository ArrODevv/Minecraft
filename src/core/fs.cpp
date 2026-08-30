#include "fs.hpp"

#include "util.hpp"

#include <sstream>

namespace minecraft {
    char FSHelper::getPathSep() {
    #if PLATFORM_WINDOWS
        return '\\';
    #else
        return '/';
    #endif
    }

    std::string FSHelper::getMainDrivePath() {
    #if PLATFORM_WINDOWS
        return "C:\\";
    #else
        return "/";
    #endif
    }

    std::string FSHelper::getAppFolder() {
        std::stringstream ss;
        char sep = FSHelper::getPathSep();

        ss << FSHelper::getMainDrivePath();
    #if PLATFORM_WINDOWS
        ss << "Users" << sep;
        ss << Util::getUsername();
        ss << sep << "AppData" << sep
           << "Roaming" << sep
           << "MinecraftCXX" << sep;
    #elif PLATFORM_LINUX
        ss << "home" << sep;
        ss << Util::getUsername();
        ss << sep << ".local" << sep
           << "MinecraftCXX" << sep;
    #elif PLATFORM_APPLE
        ss << "home" << sep;
        ss << Util::getUsername();
        ss << sep << "Library" << sep
           << "Application Support" << sep
           << "MinecraftCXX" << sep;
    #endif

        return ss.str();
    }
} // namespace minecraft
