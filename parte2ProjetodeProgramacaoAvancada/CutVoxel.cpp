#include "CutVoxel.h"
#include <iostream>

CutVoxel::CutVoxel(int _x, int _y, int _z) {
  this-> x = _x;
  this-> y = _y;
  this-> z = _z;
}

void CutVoxel::draw(Sculptor &t) {
  t.cutVoxel(x, y, z);
}