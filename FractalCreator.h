/*
 * FractalCreator.h
 *
 *  Created on: Apr 9, 2023
 *      Author: romaincaron
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <cmath>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace mainfractal {

    class FractalCreator {
    private:
        int m_width{0};
        int m_height{0};
        int m_total{0};
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap{m_width, m_height};
        ZoomList m_zoomList{m_width, m_height};

        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;
        bool m_bGotFirstRange{false};

        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);
        int getRange(int iterations) const;

    public:
        FractalCreator(int width, int height);
        ~FractalCreator();
        void addZoom(const Zoom& zoom);
        void addRange(double rangeEnd, const RGB& rgb);
        void run(string name);
    };

} /* namespace mainfractal */

#endif /* FRACTALCREATOR_H_ */