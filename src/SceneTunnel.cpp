/*
 * SceneTunnel.cpp
 *
 *  Created on: Apr 21, 2009
 *      Author: jdw
 */

#include "PixelToaster.h"
#include "SceneTunnel.h"
#include <math.h>
#include "jdw_vector3d.h"
#include "jdw_types.h"

#include <iostream>

#define AMOUNTOFCOLORS 7

SceneTunnel::SceneTunnel(const iV2& in_size)
: JDW_Scene2d(SceneType::TWOD, in_size) {
}

SceneTunnel::~SceneTunnel() {

}

void SceneTunnel::Update() {
	const dV3 tmp_origo = dV3(spScreen->GetSize().x / 2, spScreen->GetSize().y / 2, GetTotalTime());
	dV3 tmp_pixel = dV3(0, 0, GetTotalTime());
	int tmp_clr[AMOUNTOFCOLORS];


	for (int i = 0; i < AMOUNTOFCOLORS; ++i) {
		tmp_clr[i] = i * 255 / AMOUNTOFCOLORS;
	}

	for (int y = 0; y < spScreen->GetSize().x; ++y) {
		for (int x = 0; x < spScreen->GetSize().x; ++x) {
			tmp_pixel.x = x;
			tmp_pixel.y = y;

			double tmp_ddd = sin((tmp_origo - tmp_pixel).GetLength() / (spScreen->GetSize().x / 2)) * AMOUNTOFCOLORS;
			int d = 0, e = 0;
			if (tmp_pixel.x < tmp_origo.x) {
				d = tmp_origo.x / AMOUNTOFCOLORS;
				d = AMOUNTOFCOLORS - tmp_pixel.x / d;
			}

			if (tmp_pixel.y < tmp_origo.y) {
				e = tmp_origo.y / AMOUNTOFCOLORS;
				e = AMOUNTOFCOLORS - tmp_pixel.y / e;
			}

			spScreen->PutPixel(iV2(x, y), Pixel(tmp_clr[int(tmp_ddd)],tmp_clr[d],tmp_clr[e]));





			/*dV3 tmp_2clr = (tmp_origo + tmp_pixel).GetUnit().GetXP(tmp_origo).GetUnit();
			pScreen->PutPixel(iV2(x, y), PixelToaster::TrueColorPixel(tmp_clr[int(abs(tmp_2clr.x * AMOUNTOFCOLORS))],
			                                                          tmp_clr[int(abs(tmp_2clr.y * AMOUNTOFCOLORS))],
			                                                          tmp_clr[int(abs(tmp_2clr.z * AMOUNTOFCOLORS))]));
*/
			/*
			int tmp_2clr = int((tmp_origo - tmp_pixel).GetLength() / (pScreen->GetSize().x / 2) * 7);
			tmp_2clr = (tmp_2clr > 7)? 7: tmp_2clr;

			if (k == 0) {
				k++;
				tmp_old = tmp_2clr;
			}

			if (tmp_old != tmp_2clr) {
				tmp_old = tmp_2clr;

				pScreen->PutPixel(iV2(x, y), PixelToaster::TrueColorPixel(255,0,255));
			}
			else
				pScreen->PutPixel(iV2(x, y), tmp_clr[tmp_2clr]);
	*/
		}
	}
}

