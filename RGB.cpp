/*
 * RGB.cpp
 *
 *  Created on: Apr 9, 2023
 *      Author: romaincaron
 */

#include "RGB.h"

namespace mainfractal {
    RGB::RGB(double r, double g, double b): r(r), g(g), b(b) {

    }

    RGB operator-(const RGB &first, const RGB &second) {
        return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
    }
} // mainfractal