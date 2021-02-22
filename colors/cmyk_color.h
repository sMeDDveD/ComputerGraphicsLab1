#pragma once

#include "convertable.h"
#include "forward.h"
#include <ostream>

class CMYKColor : public IConvertable {
public:
    CMYKColor() = default;
    CMYKColor(double c, double m, double y, double k, bool is_exact_ = true);

    double GetC() const;
    double GetM() const;
    double GetY() const;
    double GetK() const;

    void SetC(double c);
    void SetM(double m);
    void SetY(double y);
    void SetK(double k);

    virtual bool IsExact() const override;
    virtual void Exacted() override;

    virtual XYZColor ToXYZ() const override;
    virtual RGBColor ToRGB() const override;
    virtual CMYKColor ToCMYK() const override;

    friend std::ostream &operator<<(std::ostream &os, const CMYKColor &color);

private:
    bool is_exact_ = true; 

    double c_;
    double m_;
    double y_;
    double k_;
};
