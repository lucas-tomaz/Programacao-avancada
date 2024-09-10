#include "PutVoxel.h"
#include <iostream>

PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a){
this-> x = _x;
this-> y = _y;
this-> z = _z;
this-> r = _r;
this-> g = _g;
this-> b = _b;
this-> a = _a;
}

void PutVoxel::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.putVoxel(x,y,z);
}