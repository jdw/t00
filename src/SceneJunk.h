/*
 * SceneJunk.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#ifndef SCENEJUNK
#define SCENEJUNK

#include "jdw_scene2d.h"
#include "jdw_improvedperlinnoise.h"

class SceneJunk: public JDW_Scene2d {
public:
	SceneJunk(const iV2& in_size);
	~SceneJunk();

	void Update();

private:
	boost::shared_ptr<Noise> spNoise;
	boost::shared_ptr<JDW_Image<JDW_Pixel, JDW_Pixel> > spPloj;
};

#endif
