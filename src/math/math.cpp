#include <sstream>
#include "math.h"

namespace Math {
    template<>
    std::string add(std::string a, std::string b) {
        auto ss = std::stringstream();
        ss << a << b;
        return ss.str();
    }

    int testMethod(bool val) {
        if (val)
            return 1;
        else
            return 0;
    }
}
