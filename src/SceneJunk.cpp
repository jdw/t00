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
#include "jdw_vector3d.h"
#include "jdw_rectangle.h"
#include "jdw_image.h"

#define AMOUNTOFSQUARES 3

SceneJunk::SceneJunk(const iV2& in_size)
: JDW_Scene2d(SceneType::TWOD, in_size) {
	spNoise = boost::shared_ptr<Noise>(new Noise());
	spPloj = boost::shared_ptr<JDW_Image<JDW_Pixel, JDW_Pixel> >(new JDW_Image<JDW_Pixel, JDW_Pixel>(iV2(in_size.x / 2, in_size.y / 2)));
	spPloj->Fill(JDW_Pixel(0, 170, 0));
	spPloj->SetAlpha(128);
}

SceneJunk::~SceneJunk() {
}

void SceneJunk::Update() {
	spScreen->Fill(JDW_Pixel());
	dRect tmp_rect = dRect();
	tmp_rect.SetSize(dV2(200, 200));
	Pixel tmp_clr;
	dV3 tmp_v(-1.0, -1.0, sin(double(GetTotalTime())));
	double t;

	for (int i = 0; i < AMOUNTOFSQUARES; ++i) {
		tmp_rect.SetPos(dV2(spScreen->GetSize().x / 5 + i * sin(GetTotalTime()) * 100, spScreen->GetSize().y / 7 + i * 100));
		tmp_clr.r = tmp_clr.g = tmp_clr.b = 0;

		for (int y = tmp_rect.GetPos().y; y < tmp_rect.GetPos().y + tmp_rect.GetSize().y; ++y) {
			for (int x = tmp_rect.GetPos().x; x < tmp_rect.GetPos().x + tmp_rect.GetSize().x; ++x) {
				if (x < 0 || y < 0) continue;
				tmp_v.x = tmp_v.y = -1.0;
				tmp_v.x = 2 * double(x) / double(tmp_rect.GetSize().x);
				tmp_v.y = 2 * double(y) / double(tmp_rect.GetSize().y);
				t = spNoise->Noise(tmp_v.x, tmp_v.y, tmp_v.z) * 30.0;

				switch (i % 3) {
					case 0: {
						tmp_clr.r = 128 + 128 * sin(t);
						tmp_clr.r = (tmp_clr.r == 0)? 1: tmp_clr.r;
					} break;

					case 1: {
						tmp_clr.g = 128 + 128 * sin(t);
						tmp_clr.g = (tmp_clr.g == 0)? 1: tmp_clr.g;
					} break;

					case 2: {
						tmp_clr.b = 128 + 128 * sin(t);
						tmp_clr.b = (tmp_clr.b == 0)? 1: tmp_clr.b;
					} break;
				}

				spScreen->PutPixel(iV2(x, y), tmp_clr, JDW_PixelDrawMode::ADD);

			}
		}
	}

	for (int i = 0; i < AMOUNTOFSQUARES; ++i) {
		tmp_rect.SetPos(dV2(spScreen->GetSize().x / 5 + i * sin(GetTotalTime()) * 100, spScreen->GetSize().y / 7 + i * 100));

		spScreen->DrawLine(iV2(tmp_rect.GetPos().x, tmp_rect.GetPos().y - 1),
		                   iV2(tmp_rect.GetPos().x + tmp_rect.GetSize().x, tmp_rect.GetPos().y - 1), JDW_Pixel(255,255,255), JDW_PixelDrawMode::ONBLACKONLY);
		spScreen->DrawLine(iV2(tmp_rect.GetPos().x, tmp_rect.GetPos().y + tmp_rect.GetSize().y),
		                   iV2(tmp_rect.GetPos().x + tmp_rect.GetSize().x, tmp_rect.GetPos().y + tmp_rect.GetSize().y), JDW_Pixel(255,255,255), JDW_PixelDrawMode::ONBLACKONLY);
		spScreen->DrawLine(iV2(tmp_rect.GetPos().x - 1, tmp_rect.GetPos().y),
		                   iV2(tmp_rect.GetPos().x - 1, tmp_rect.GetPos().y + tmp_rect.GetSize().y), JDW_Pixel(255,255,255), JDW_PixelDrawMode::ONBLACKONLY);
		spScreen->DrawLine(iV2(tmp_rect.GetPos().x + tmp_rect.GetSize().x + 1, tmp_rect.GetPos().y),
		                   iV2(tmp_rect.GetPos().x + tmp_rect.GetSize().x + 1, tmp_rect.GetPos().y + tmp_rect.GetSize().y), JDW_Pixel(255,255,255), JDW_PixelDrawMode::ONBLACKONLY);

	}

	spScreen->Blit(iV2(spScreen->GetSize().x / 4, spScreen->GetSize().y / 4), spPloj.get(), JDW_PixelDrawMode::ALPHA);
}
