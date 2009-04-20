/*
 * SceneBalls.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#ifndef SCENEBALLS
#define SCENEBALLS

#include "jdw_scene2d.h"
#include "MetaBall.h"
#include "jdw_improvedperlinnoise.h"

#define AMOUNTOFBALLS 3

class SceneBalls: public JDW_Scene2d {
public:
	SceneBalls(const iV2& in_size);
	~SceneBalls();

	void Update();

private:
	MetaBall* ball[AMOUNTOFBALLS];
	Noise* pNoise;
};

#endif
