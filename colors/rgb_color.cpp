#include "rgb_color.h"

#include <algorithm>
#include <cmath>

#include "cmyk_color.h"
#include "utilities.h"
#include "xyz_color.h"

RGBColor::RGBColor(uint8_t r, uint8_t g, uint8_t b, bool is_exact)
    : r_(r), g_(g), b_(b), is_exact_(is_exact) {
}

uint8_t RGBColor::GetR() const {
    return r_;
}

uint8_t RGBColor::GetG() const {
    return g_;
}

uint8_t RGBColor::GetB() const {
    return b_;
}

bool RGBColor::IsExact() const {
    return is_exact_;
}

void RGBColor::Exacted() {
    is_exact_ = true;
}

XYZColor RGBColor::ToXYZ() const {
    double rn = FRGB(r_ / 255.0) * 100.0;
    double gn = FRGB(g_ / 255.0) * 100.0;
    double bn = FRGB(b_ / 255.0) * 100.0;

    return XYZColor(0.412453 * rn + 0.357580 * gn + 0.180423 * bn,
                    0.212671 * rn + 0.715160 * gn + 0.072169 * bn,
                    0.019334 * rn + 0.119193 * gn + 0.950227 * bn);
}

RGBColor RGBColor::ToRGB() const {
    return *this;
}

CMYKColor RGBColor::ToCMYK() const {
    double r = r_ / 255.0;
    double b = b_ / 255.0;
    double g = g_ / 255.0;

    double k = 1.0 - std::max({r, g, b});

    return CMYKColor((1.0 - r - k) / (1.0 - k), (1.0 - g - k) / (1.0 - k),
                     (1.0 - b - k) / (1.0 - k), k, is_exact_);
}
std::ostream &operator<<(std::ostream &os, const RGBColor &color) {
    os << " r_: " << static_cast<int>(color.r_) << " g_: " << static_cast<int>(color.g_)
       << " b_: " << static_cast<int>(color.b_);
    return os;
}
void RGBColor::SetR(uint8_t r) {
    r_ = r;
}

void RGBColor::SetG(uint8_t g) {
    g_ = g;
}

void RGBColor::SetB(uint8_t b) {
    b_ = b;
}
