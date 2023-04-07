/*
 * main.cpp
 *
 *  Created on: Apr 7, 2023
 *      Author: romaincaron
 */

#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace mainfractal;

int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
            // Scaling the x and y coordinates to the range -1 to +1
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t red = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

            bitmap.setPixel(x, y, red, 0, 0);

            if (red < min) min = red;
            if (red > max) max = red;
		}
	}

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
