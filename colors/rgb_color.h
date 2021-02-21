#pragma once

#include <cstdint>
#include <ostream>

#include "convertable.h"
#include "forward.h"

class RGBColor : public IConvertable {
public:
    RGBColor() = default;
    RGBColor(uint8_t r, uint8_t g, uint8_t b, bool is_exact = true);

    uint8_t GetR() const;
    uint8_t GetG() const;
    uint8_t GetB() const;

    void SetR(uint8_t r);
    void SetG(uint8_t g);
    void SetB(uint8_t b);

    virtual bool IsExact() const override;

    virtual XYZColor ToXYZ() const override;
    virtual RGBColor ToRGB() const override;
    virtual CMYKColor ToCMYK() const override;

    friend std::ostream &operator<<(std::ostream &os, const RGBColor &color);

private:
    bool is_exact_ = true;

    uint8_t r_;
    uint8_t g_;
    uint8_t b_;
};
