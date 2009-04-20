/*
 * main.cpp
 *
 *  Created on: Apr 18, 2009
 *      Author: jdw
 */

#include <iostream>

#include "jdw_misc.h"
#include "jdw_test.h"
#include "PixelToaster.h"
#include "jdw_vector3d.h"
#include "jdw_vector2d.h"
#include "jdw_improvedperlinnoise.h"
#include "jdw_image.h"
//#include "jdw_screen.h"
#include "SceneBalls.h"
#include "SceneJunk.h"
#include "jdw_list.h"

using namespace PixelToaster;

namespace SceneNowPlaying {
	enum Enum {
		JUNK = 0,
		BALL,

		MAX
	};
}

int main() {
    iV2 size = iV2(640, 480);
	Timer timer;
	double t0 = timer.time();
    Display display( "t00", size.x, size.y, Output::Windowed);
    SceneNowPlaying::Enum current = SceneNowPlaying::BALL;
    JDW_Scene* pScene;
    pScene = new SceneBalls(size);

    while (display.open()) {
    	if (timer.time() - t0 < FPS) timer.wait(FPS - (timer.time() - t0));
    	t0 = timer.time();

    	switch (current) {
			case SceneNowPlaying::JUNK: {
				((SceneJunk*)pScene)->SetDeltaTime(t0);
				((SceneJunk*)pScene)->UpdateTotalTime();
				((SceneJunk*)pScene)->Update();
				display.update(((SceneJunk*)pScene)->GetImage()->GetPixels());

				if (pScene->GetTotalTime() > 600.0) {
					delete pScene;
					pScene = new SceneBalls(size);
					current = SceneNowPlaying::BALL;
				}
			} break;

			case SceneNowPlaying::BALL: {
				((SceneBalls*)pScene)->SetDeltaTime(t0);
				((SceneBalls*)pScene)->UpdateTotalTime();
				((SceneBalls*)pScene)->Update();
				display.update(((SceneBalls*)pScene)->GetImage()->GetPixels());

				if (pScene->GetTotalTime() > 600.0) {
					delete pScene;
					pScene = new SceneJunk(size);
					current = SceneNowPlaying::JUNK;
				}
			} break;

			case SceneNowPlaying::MAX: {

			} break;
		}
    }

    return 0;
}
