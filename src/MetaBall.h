/*
 * MetaBall.h
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#ifndef METABALL
#define METABALL

#include "jdw_vector2d.h"

class MetaBall {
public:
	MetaBall();
	~MetaBall();

	dV2 pos; // Positons
	double rad; // Radius
	double ang; // Angle
	double dis; // Distance from origo
	int dir; // Leaving or nearing origo

	double Value(const dV2 in_pos);
};

#endif
