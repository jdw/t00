/*
 * main.cpp
 *
 *  Created on: Apr 18, 2009
 *      Author: jdw
 */

#include "PixelToaster.h"
#include "jdw_vector3d.h"
#include "jdw_vector2d.h"
#include "jdw_improvedperlinnoise.h"

using namespace PixelToaster;

int main() {
    const iV2 size = iV2(320, 240);
    Display display("t00", size.x, size.y, Output::Fullscreen);
    Noise* pNoise = new Noise();

	vector<Pixel> pixels(size.x * size.y);

    while (display.open())
    {
        unsigned int index = 0;

        for ( int y = 0; y < height; ++y )
        {
            for ( int x = 0; x < width; ++x )
            {
                pixels[index].r = pNoise->Noise(x, y, 0);

				++index;
            }
        }

		display.update( pixels );
    }
}
