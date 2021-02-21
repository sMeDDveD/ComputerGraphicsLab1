#pragma once

static inline bool stub;

double FRGB(double x);
double FXYZ(double x);

template <typename T>
const T& Clamp(const T& min, const T& max, const T& value, bool* clamped = nullptr) {
    if (!clamped) {
        clamped = &stub;
    }

    *clamped = true;

    if (value > max) {
        return max;
    }

    if (value < min) {
        return min;
    }

    *clamped = false;

    return value;
}
