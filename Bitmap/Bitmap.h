/*
 * Bitmap.h
 *
 *  Created on: Apr 7, 2023
 *      Author: romaincaron
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
using namespace std;

namespace mainfractal {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	unique_ptr<uint8_t[]> m_pPixels{nullptr};


public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(string filename);
	virtual ~Bitmap();
};

} /* namespace mainfractal */

#endif /* BITMAP_H_ */
