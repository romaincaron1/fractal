/*
 * Mandelbrot.cpp
 *
 *  Created on: Apr 7, 2023
 *      Author: romaincaron
 */

#include "Mandelbrot.h"
#include <complex>
#include <iostream>

using namespace std;

namespace mainfractal {

    Mandelbrot::Mandelbrot() {

    }


    int Mandelbrot::getIterations(double x, double y) {

        complex<double> z = 0;
        complex<double> c(x, y);

        int iterations = 0;

        while(iterations < MAX_ITERATIONS) {
            z = z*z + c;

            if(abs(z) > 2) {
                break;
            }

            iterations++;
        }

        return iterations;
    }

    Mandelbrot::~Mandelbrot() {

    }

}

#include "Mandelbrot.h"
