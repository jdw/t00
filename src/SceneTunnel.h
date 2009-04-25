/*
 * SceneTunnel.h
 *
 *  Created on: Apr 21, 2009
 *      Author: jdw
 */

#ifndef SCENETUNNEL
#define SCENETUNNEL

#include "jdw_scene2d.h"
#include "jdw_image.h"
#include "jdw_types.h"

class SceneTunnel: public JDW_Scene2d {
public:
	SceneTunnel(const iV2& in_size);
	~SceneTunnel();

	void Update();

private:
};

#endif
