/*
 * MetaBall.cpp
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#include "MetaBall.h"
#include <math.h>

MetaBall::MetaBall() {
	pos = dV2();
	rad = 5.0;
	ang = 0.0;
	dir = 1;
	dis = 0.0f;
}

MetaBall::~MetaBall() {

}

double MetaBall::Value(const dV2 in_pos) {
	return (double)(rad / sqrt((in_pos.x - pos.x) * (in_pos.x - pos.x) + (in_pos.y - pos.y) * (in_pos.y - pos.y)));
}
