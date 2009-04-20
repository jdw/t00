/*
 * MetaBall.cpp
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#include "MetaBall.h"
#include <math.h>
#include <iostream>

MetaBall::MetaBall()
: JDW_Circle<dV2>() {
	ang = 0.0;
	dir = 1;
	dis = 0.0f;
}

MetaBall::~MetaBall() {

}

double MetaBall::Value(const dV2 in_pos) {
	return GetRadius() / GetPos().GetDist(dV2(in_pos.x, in_pos.y));
}
