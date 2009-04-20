/*
 * SceneJunk.cpp
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#include "PixelToaster.h"
#include "SceneJunk.h"
#include <math.h>
#include "jdw_improvedperlinnoise.h"
#include <iostream>
#include "jdw_vector3d.h"

SceneJunk::SceneJunk(const iV2& in_size)
: JDW_Scene2d(SceneType::TWOD, in_size) {
	pNoise = new Noise();

	pR = new Image(iV2(pScreen->GetSize().x / 3, pScreen->GetSize().y / 3));
	//pG = new Image(iV2(pScreen->GetSize().x / 3, pScreen->GetSize().y / 3));
	//pB = new Image(iV2(pScreen->GetSize().x / 3, pScreen->GetSize().y / 3));

}

SceneJunk::~SceneJunk() {
	delete pR;
	delete pNoise;
}

void SceneJunk::Update() {
	PixelToaster::TrueColorPixel tmp_clr;
	dV3 tmp_v(-1.0, -1.0, sin(double(GetTotalTime()) / double(1000)));
	double t;

	iV2 tmp_rOffset = iV2(0,0);
	iV2 tmp_gOffset = iV2(50, 50);
	iV2 tmp_bOffset = iV2(50, 50);
	iV2 tmp_size = pR->GetSize();

	for (int y = tmp_rOffset.y; y < tmp_rOffset.y + tmp_size.y; ++y) {
		for (int x = tmp_rOffset.x; x < tmp_rOffset.x + tmp_size.x; ++x) {
			tmp_v.x = tmp_v.y = -1.0;
			tmp_v.x = 2 * double(x) / double(tmp_size.x);
			tmp_v.y = 2 * double(y) / double(tmp_size.y);
			t = pNoise->Noise(tmp_v.x, tmp_v.y, tmp_v.z) * 70.0;

			tmp_clr.r = 128 + 128 * sin(t);
			pR->PutPixel(iV2(x, y), tmp_clr);

		}
	}
/*
	tmp_clr.r = tmp_clr.g = tmp_clr.b = 0;
	tmp_size = pG->GetSize();
	for (int y = 0; y < tmp_size.y; ++y) {
		for (int x = 0; x < tmp_size.x; ++x) {
			tmp_v.x = tmp_v.y = -1.0;
			tmp_v.x = 2 * double(tmp_gOffset.x - x) / double(tmp_gOffset.y - tmp_size.x);
			tmp_v.y = 2 * double(tmp_gOffset.y - y) / double(tmp_gOffset.y - tmp_size.y);
			t = pNoise->Noise(tmp_v.x, tmp_v.y, tmp_v.z) * 30.0;

			tmp_clr.g = 128 + 128 * sin(t);
			pG->PutPixel(iV2(x, y), tmp_clr);
		}
	}

	tmp_clr.r = tmp_clr.g = tmp_clr.b = 0;
	tmp_size = pB->GetSize();
	for (int y = 0; y < tmp_size.y; ++y) {
		for (int x = 0; x < tmp_size.x; ++x) {
			tmp_v.x = tmp_v.y = -1.0;
			tmp_v.x = 2 * double(tmp_bOffset.x - x) / double(tmp_bOffset.y - tmp_size.x);
			tmp_v.y = 2 * double(tmp_bOffset.y - y) / double(tmp_bOffset.y - tmp_size.y);
			t = pNoise->Noise(tmp_v.x, tmp_v.y, tmp_v.z) * 50.0;

			tmp_clr.b = 128 + 128 * sin(t);
			pB->PutPixel(iV2(x, y), tmp_clr);
		}
	}
*/
	pScreen->Blit(tmp_rOffset, pR);
	//pScreen->Blit(tmp_gOffset, pG);
//	pScreen->Blit(tmp_bOffset, pB);

}
