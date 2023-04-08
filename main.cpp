/*
 * main.cpp
 *
 *  Created on: Apr 7, 2023
 *      Author: romaincaron
 */

#include "FractalCreator.h"
#include "RGB.h"
#include <iostream>

using namespace std;
using namespace mainfractal;

int main() {

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 255));
    fractalCreator.addRange(0.05, RGB(255, 110, 71));
    fractalCreator.addRange(0.08, RGB(255, 215, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("test.bmp");

    return 0;
}
