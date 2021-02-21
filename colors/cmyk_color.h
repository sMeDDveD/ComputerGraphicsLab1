#pragma once

#include "convertable.h"
#include "forward.h"
#include <ostream>

class CMYKColor : public IConvertable {
public:
    CMYKColor() = default;
    CMYKColor(double c, double m, double y, double k);

    double GetC() const;
    double GetM() const;
    double GetY() const;
    double GetK() const;

    void SetC(double c);
    void SetM(double m);
    void SetY(double y);
    void SetK(double k);

    virtual XYZColor ToXYZ() const override;
    virtual RGBColor ToRGB() const override;
    virtual CMYKColor ToCMYK() const override;

    friend std::ostream &operator<<(std::ostream &os, const CMYKColor &color);

private:
    double c_;
    double m_;
    double y_;
    double k_;
};
