/*
 * Mandelbrot.h
 *
 *  Created on: Apr 7, 2023
 *      Author: romaincaron
 */

#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H

namespace mainfractal {

    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;

    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);
    };

}

#endif //FRACTAL_MANDELBROT_H
