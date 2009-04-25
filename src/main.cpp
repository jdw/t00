/*
 * main.cpp
 *
 *  Created on: Apr 18, 2009
 *      Author: jdw
 */

#include <iostream>
#include <vector>

#include "jdw_types.h"

#include "jdw_misc.h"
#include "jdw_test.h"
#include "PixelToaster.h"
#include "jdw_vector3d.h"
#include "jdw_vector2d.h"
#include "jdw_improvedperlinnoise.h"
#include "jdw_image.h"
#include "SceneBalls.h"
#include "SceneJunk.h"
#include "SceneTunnel.h"
#include "jdw_list.h"

using namespace PixelToaster;

namespace SceneNowPlaying {
	enum Enum {
		JUNK = 0,
		BALL,
		TUNNEL,

		MAX
	};
}

int main() {
    iV2 size = iV2(640, 480);
	Timer timer;
	double dT = timer.time(); // Start
    Display display( "t00", size.x, size.y, Output::Windowed);
    SceneNowPlaying::Enum current = SceneNowPlaying::TUNNEL;
    JDW_Scene* pScene;
    pScene = new SceneTunnel(size);

    PixelToaster::TrueColorPixel pixels[size.x * size.y];
    std::vector<JDW_Pixel> fromScene;

    while (display.open()) {
    	dT = timer.delta();
    	if (dT < FPS) timer.wait(FPS - dT);

    	switch (current) {
			case SceneNowPlaying::TUNNEL: {
				((SceneTunnel*)pScene)->SetDeltaTime(dT);
				((SceneTunnel*)pScene)->UpdateTotalTime();
				((SceneTunnel*)pScene)->Update();

				fromScene = (*((SceneTunnel*)pScene)->GetScreen()->GetPixels());
				for (int i = 0; i < size.x * size.y; ++i)
					pixels[i].integer = fromScene[i].integer;

				display.update(pixels);

				if (pScene->GetTotalTime() > 2.0) {
					delete (SceneTunnel*)pScene;
					pScene = new SceneJunk(size);
					current = SceneNowPlaying::JUNK;
				}
    		} break;

			case SceneNowPlaying::JUNK: {
				((SceneJunk*)pScene)->SetDeltaTime(dT);
				((SceneJunk*)pScene)->UpdateTotalTime();
				((SceneJunk*)pScene)->Update();


				fromScene = (*((SceneJunk*)pScene)->GetScreen()->GetPixels());
				for (int i = 0; i < size.x * size.y; ++i)
					pixels[i].integer = fromScene[i].integer;


				//&pixels = pFromScene = (std::vector<PixelToaster::TrueColorPixel>*)((SceneJunk*)pScene)->GetScreen()->GetPixels();
				display.update(pixels);

				if (pScene->GetTotalTime() > 20.0) {
					delete (SceneJunk*)pScene;
					pScene = new SceneBalls(size);
					current = SceneNowPlaying::BALL;
				}
			} break;

			case SceneNowPlaying::BALL: {
				((SceneBalls*)pScene)->SetDeltaTime(dT);
				((SceneBalls*)pScene)->UpdateTotalTime();
				((SceneBalls*)pScene)->Update();

				fromScene = (*((SceneBalls*)pScene)->GetScreen()->GetPixels());
				for (int i = 0; i < size.x * size.y; ++i)
					pixels[i].integer = fromScene[i].integer;
				display.update(pixels);

				if (pScene->GetTotalTime() > 20.0) {
					delete (SceneBalls*)pScene;
					pScene = new SceneTunnel(size);
					current = SceneNowPlaying::TUNNEL;
				}
			} break;

			case SceneNowPlaying::MAX: {

			} break;
		}
    }

    return 0;
}
