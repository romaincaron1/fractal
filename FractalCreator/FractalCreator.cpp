/*
 * FractalCreator.h
 *
 *  Created on: Apr 9, 2023
 *      Author: romaincaron
 */

#include "FractalCreator.h"
#include <iostream>

namespace mainfractal {

    /*
     * addRange
     * --------------------
     * Adds a range to the fractal creator
     * --------------------
     * @param rangeEnd: the end of the range
     * @param rgb: the color of the range
     * --------------------
     * @return void
     */
    void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
        m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        m_colors.push_back(rgb);

        if (m_bGotFirstRange) {
            m_rangeTotals.push_back(0);
        }

        m_bGotFirstRange = true;
    }

    /*
     * getRange
     * --------------------
     * Gets the range of the fractal creator
     * --------------------
     * @param iterations: the number of iterations
     * --------------------
     * @return int : the range
     */
    int FractalCreator::getRange(int iterations) const {
        int range = 0;

        for (int i = 1; i < m_ranges.size(); i++) {

            if (m_ranges[i] > iterations) {
                break;
            }

            range = i;
        }

        return range;
    }

    /*
     * addZoom
     * --------------------
     * Adds a zoom to the fractal creator
     * --------------------
     * @param zoom: the zoom to be added
     * --------------------
     * @return void
     */
    void FractalCreator::addZoom(const Zoom& zoom) {
        m_zoomList.add(zoom);
    }

    /*
     * FractionCreator
     * --------------------
     * Constructor for the fractal creator
     * --------------------
     * @param width: the width of the fractal
     * @param height: the height of the fractal
     */
    FractalCreator::FractalCreator(int width, int height) :
            m_width(width), m_height(height), m_histogram(
            new int[Mandelbrot::MAX_ITERATIONS] { 0 }), m_fractal(
            new int[m_width * m_height] { 0 }), m_bitmap(m_width, m_height), m_zoomList(
            m_width, m_height) {
        // TODO Auto-generated constructor stub
        m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
    }

    /*
     * ~FractionCreator
     * --------------------
     * Destructor for the fractal creator
     */
    FractalCreator::~FractalCreator() {
    }

    /*
     * calculateIteration
     * --------------------
     * Calculates the number of iterations for each pixel
     * --------------------
     * @return void
     */
    void FractalCreator::calculateIteration() {

        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                pair<double, double> coords = m_zoomList.doZoom(x, y);

                int iterations = Mandelbrot::getIterations(coords.first,
                                                           coords.second);

                m_fractal[y * m_width + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    m_histogram[iterations]++;
                }

            }
        }
    }

    /*
     * calculateRangeTotals
     * --------------------
     * Calculates the total number of iterations for each range
     * --------------------
     * @return void
     */
    void FractalCreator::calculateRangeTotals() {

        int rangeIndex = 0;

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
            int pixels = m_histogram[i];

            if (i >= m_ranges[rangeIndex + 1]) {
                rangeIndex++;
            }

            m_rangeTotals[rangeIndex] += pixels;
        }
    }

    /*
     * caculateTotalIterations
     * --------------------
     * Calculates the total number of iterations
     * --------------------
     * @return void
     */
    void FractalCreator::calculateTotalIterations() {

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
            m_total += m_histogram[i];
        }
    }

    /*
     * drawFractal
     * --------------------
     * Draws the fractal
     * --------------------
     * @return void
     */
    void FractalCreator::drawFractal() {

        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {

                int iterations = m_fractal[y * m_width + x];

                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB& startColor = m_colors[range];
                RGB& endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if (iterations != Mandelbrot::MAX_ITERATIONS) {

                    int totalPixels = 0;

                    for (int i = rangeStart; i <= iterations; i++) {
                        totalPixels += m_histogram[i];
                    }

                    red = startColor.r
                          + colorDiff.r * (double) totalPixels / rangeTotal;
                    green = startColor.g
                            + colorDiff.g * (double) totalPixels / rangeTotal;
                    blue = startColor.b
                           + colorDiff.b * (double) totalPixels / rangeTotal;

                }

                m_bitmap.setPixel(x, y, red, green, blue);

            }
        }

    }

    /*
     * writeBitmap
     * --------------------
     * Writes the bitmap to a file
     * --------------------
     * @param name: the name of the file
     * --------------------
     * @return void
     */
    void FractalCreator::writeBitmap(string name) {
        m_bitmap.write(name);

        cout << "Finished" << endl;
    }

    /*
     * run
     * --------------------
     * Runs the fractal creator
     * --------------------
     * @param name: the name of the file
     * --------------------
     * @return void
     */
    void FractalCreator::run(string name) {
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }

} /* namespace mainfractal */
