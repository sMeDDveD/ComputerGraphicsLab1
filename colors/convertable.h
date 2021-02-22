#pragma once

#include "forward.h"

class IConvertable {
public:
    virtual bool IsExact() const {
        return true;
    }

    virtual void Exacted() {
        return;
    }

    virtual XYZColor ToXYZ() const = 0;
    virtual RGBColor ToRGB() const = 0;
    virtual CMYKColor ToCMYK() const = 0;
};
