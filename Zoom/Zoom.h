/*
 * Zoom.h
 *
 *  Created on: Apr 8, 2023
 *      Author: romaincaron
 */

#ifndef FRACTAL_ZOOM_H
#define FRACTAL_ZOOM_H

namespace mainfractal {

    struct Zoom {
        int x{0};
        int y{0};
        double scale{0.0};

        Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {}
    };

}

#endif //FRACTAL_ZOOM_H
