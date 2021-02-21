#pragma once

#include "convertable.h"
#include "forward.h"
#include <ostream>

class XYZColor : public IConvertable {
public:
    XYZColor() = default;
    XYZColor(double x, double y, double z);

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);

    virtual XYZColor ToXYZ() const override;
    virtual RGBColor ToRGB() const override;
    virtual CMYKColor ToCMYK() const override;

    friend std::ostream &operator<<(std::ostream &os, const XYZColor &color);

private:
    double x_;
    double y_;
    double z_;
};
