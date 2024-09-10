#include "PutEllipsoid.h"
#include <iostream>

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz,float _r, float _g, float _b, float _a){
  this-> xcenter = _xcenter;
  this-> ycenter = _ycenter;
  this-> zcenter = _zcenter;
  this-> rx = _rx;
  this-> ry = _ry;
  this-> rz = _rz;
  this-> r = _r;
  this-> g = _g;
  this-> b = _b;
  this-> a = _a;
}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = xcenter - rx; i <= xcenter+rx; i++){
        for(int j = ycenter - ry; j <= ycenter + ry; j++){
            for(int k = zcenter - rz; k <= zcenter+rz; k++){
                float dx = xcenter - i;
                float dy = ycenter - j;
                float dz = zcenter - k;
                if((dx*dx)/(rx*rx) + (dy*dy)/(ry*ry) + (dz*dz)/(rz*rz) <= 1){
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}