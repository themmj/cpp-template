#include <iostream>
#include "math/math.h"

int main(int argc, char** argv) {
    std::cout << Math::add<std::string>("Hello", " World\n");
    std::cout << Math::add(34, 35);
    return 0;
}
