/*
 * RGB.h
 *
 *  Created on: Apr 9, 2023
 *      Author: romaincaron
 */

#ifndef FRACTAL_RGB_H
#define FRACTAL_RGB_H

namespace mainfractal {

    struct RGB {
        double r;
        double g;
        double b;
        RGB(double r, double g, double b);
    };

    RGB operator-(const RGB &first, const RGB &second);

} // mainfractal

#endif //FRACTAL_RGB_H
