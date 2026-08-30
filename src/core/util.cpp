#include "util.hpp"

#if PLATFORM_WINDOWS
#include <windows.h>
#include <lmcons.h>
#endif // PLATFORM_WINDOWS

#if PLATFORM_LINUX
#include <pwd.h>
#include <cstdlib>
#endif // PLATFORM_LINUX

#if PLATFORM_APPLE
#include <cstdlib>
#endif // PLATFORM_APPLE

namespace minecraft {
    std::string Util::getUsername() {
    #if PLATFORM_WINDOWS
        char username[UNLEN+1];
        DWORD username_len = UNLEN+1;
        GetUserNameA(username, &username_len);

        return std::string(username);
    #elif PLATFORM_LINUX
        register struct passwd* pw;
        register uid_t uid;
        
        uid = geteuid();
        pw = getpwuid(uid);
        if(pw) {
            return std::string(pw->pw_name);
        }

        char* username = std::getenv("USER");
        return std::string(username);
    #elif PLATFORM_APPLE
        // TODO: there must be a better way, but I couldn't find anything online
        char* username = std::getenv("USER");
        return std::string(username);
    #endif
    }
} // namespace minecraft
