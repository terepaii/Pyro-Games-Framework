#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <cstdlib>

/**
* A simple utils class that provides helper functions for general programming needs
*/
class Utils
{
public:
    template<class T>
    static std::string numberToString(T num)
    {
        std::ostringstream ss;
        ss << num;
        return ss.str();
    }

    static int generateRand(int min, int max)
    {
        return rand() % (max - min) + min;
    }
};

#endif //UTILS_H