/*
 * SceneBalls.cpp
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#include "jdw_types.h"
#include "jdw_pixel.h"
#include "SceneBalls.h"

#include <math.h>
#include <iostream>

SceneBalls::SceneBalls(const iV2& in_size)
: JDW_Scene2d(SceneType::TWOD, in_size) {
	for (int i = 0; i < AMOUNTOFBALLS; i++) {
		ball[i] = new MetaBall();
		ball[i]->SetRadius(5.0);
	}
	pNoise = new Noise();

}

SceneBalls::~SceneBalls() {
	for (int i = 0; i < AMOUNTOFBALLS; i++)
		delete ball[i];

	delete pNoise;
}

void SceneBalls::Update() {
	spScreen->Fill(JDW_Pixel());

	double tmp_val;
	Pixel tmp_clr;
	iV2 tmp_halfScreen = iV2(spScreen->GetSize().x / 2, spScreen->GetSize().y / 2);
	iV2 tmp_pos;

	ball[0]->ang -= 0.1;
	ball[0]->SetPos(dV2(cos(ball[0]->ang) * spScreen->GetSize().x / 3 + tmp_halfScreen.x,
	                   sin(ball[0]->ang) * spScreen->GetSize().y / 3 + tmp_halfScreen.y));
	ball[1]->ang += 0.1;
	ball[1]->SetPos(dV2(cos(ball[1]->ang) * spScreen->GetSize().x / 2 + tmp_halfScreen.x,
	                   sin(ball[1]->ang) * spScreen->GetSize().y / 2 + tmp_halfScreen.y));
	ball[2]->ang += 0.1;
	ball[2]->SetPos(dV2(cos(ball[2]->ang) * spScreen->GetSize().x / 7 + tmp_halfScreen.x,
                   sin(ball[2]->ang) * spScreen->GetSize().y / 7 + tmp_halfScreen.y));


	for (tmp_pos.y = 0; tmp_pos.y < spScreen->GetSize().y; ++tmp_pos.y) {
		for (tmp_pos.x = 0; tmp_pos.x < spScreen->GetSize().x; ++tmp_pos.x) {
			tmp_val = 0.0;

			for (int i = 0; i < AMOUNTOFBALLS; i++) {
				tmp_val += ball[i]->Value(dV2(tmp_pos.x, tmp_pos.y));
			}

			tmp_val *= 2000;

			if (tmp_val > 200) {
				tmp_clr.r = 200;
			}
			else if (tmp_val < 170) {
				tmp_clr.r = tmp_clr.g = tmp_clr.b = 255;
			}
			else {
				tmp_clr.r = tmp_clr.g = tmp_clr.b = 150;
			}


/*
			tmp_clr.r = pNoise->Noise(double(tmp_pos.x) / double(pScreen->GetSize().x),
			                          double(tmp_pos.y) / double(pScreen->GetSize().y),
			                          0.0);
*/
			spScreen->PutPixel(tmp_pos, tmp_clr);
		}
	}
}

