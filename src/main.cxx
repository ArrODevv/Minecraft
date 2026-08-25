#include "runtime.hpp"

#include <iostream>

int main(int argc, char** argv) {
    using namespace minecraft;
    Runtime::getInstance().getLogger().testLog();
    Runtime::getInstance().getLogger().testLog();

    for(int i = 65535; i >= 0; i--) {
        std::cout << "Loop " << i << std::endl;
    }

    Runtime::getInstance().getLogger().testLog();
    Runtime::getInstance().getLogger().testLog();

    return 0;
}
