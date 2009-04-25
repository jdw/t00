/*
 * MetaBall.h
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#ifndef METABALL
#define METABALL

#include "jdw_types.h"
#include "jdw_vector2d.h"
#include "jdw_circle.h"


class MetaBall: public JDW_Circle<dV2> {
public:
	MetaBall();
	~MetaBall();

	double ang; // Angle
	double dis; // Distance from origo
	int dir; // Leaving or nearing origo

	double Value(const dV2 in_pos);
};

#endif
