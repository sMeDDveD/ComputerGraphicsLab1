#include "cmyk_color.h"
#include "rgb_color.h"
#include "xyz_color.h"

CMYKColor::CMYKColor(double c, double m, double y, double k)
    : c_(c), m_(m), y_(y), k_(k) {}

double CMYKColor::GetC() const { return c_; }

double CMYKColor::GetM() const { return m_; }

double CMYKColor::GetY() const { return y_; }

double CMYKColor::GetK() const { return k_; }

XYZColor CMYKColor::ToXYZ() const { return this->ToRGB().ToXYZ(); }

RGBColor CMYKColor::ToRGB() const {
  return RGBColor(255 * (1 - c_) * (1 - k_), 255 * (1 - m_) * (1 - k_),
                  255 * (1 - y_) * (1 - k_));
}

CMYKColor CMYKColor::ToCMYK() const { return *this; }
std::ostream &operator<<(std::ostream &os, const CMYKColor &color) {
  os << " c_: " << color.c_ << " m_: " << color.m_ << " y_: " << color.y_
     << " k_: " << color.k_;
  return os;
}

void CMYKColor::SetC(double c) { c_ = c; }

void CMYKColor::SetM(double m) { m_ = m; }

void CMYKColor::SetY(double y) { y_ = y; }

void CMYKColor::SetK(double k) { k_ = k; }
