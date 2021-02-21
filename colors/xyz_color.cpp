#include "xyz_color.h"
#include "cmyk_color.h"
#include "rgb_color.h"

#include "utilities.h"

XYZColor::XYZColor(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double XYZColor::GetX() const { return x_; }

double XYZColor::GetY() const { return y_; }

double XYZColor::GetZ() const { return z_; }

XYZColor XYZColor::ToXYZ() const { return *this; }

RGBColor XYZColor::ToRGB() const {
  double x = x_ / 100;
  double y = y_ / 100;
  double z = z_ / 100;

  double rn = 3.2406 * x - 1.5372 * y - 0.4986 * z;
  double gn = -0.9689 * x + 1.8758 * y + 0.0415 * z;
  double bn = 0.0557 * x - 0.2040 * y + 1.0570 * z;

  return RGBColor(FXYZ(rn) * 255, FXYZ(gn) * 255, FXYZ(bn) * 255);
}

CMYKColor XYZColor::ToCMYK() const { return this->ToRGB().ToCMYK(); }
std::ostream &operator<<(std::ostream &os, const XYZColor &color) {
  os << " x_: " << color.x_ << " y_: " << color.y_ << " z_: " << color.z_;
  return os;
}

void XYZColor::SetX(double x) { x_ = x; }

void XYZColor::SetY(double y) { y_ = y; }

void XYZColor::SetZ(double z) { z_ = z; }
