#include "utilities.h"

#include <cmath>

double FRGB(double x) {
    if (x >= 0.04045) {
        return std::pow((x + 0.055) / 1.055, 2.4);
    } else {
        return x / 12.92;
    }
}

double FXYZ(double x) {
    if (x >= 0.0031308) {
        return 1.055 * std::pow(x, 1.0 / 2.4) - 0.055;
    } else {
        return x * 12.92;
    }
}
