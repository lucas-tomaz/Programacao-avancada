#include "CutEllipsoid.h"
#include <iostream>

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz){
  this-> xcenter = _xcenter;
  this-> ycenter = _ycenter;
  this-> zcenter = _zcenter;
  this-> rx = _rx;
  this-> ry = _ry;
  this-> rz = _rz;
}

void CutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);
  for(int i = xcenter-rx; i <= xcenter+rx; i++){
      for(int j = ycenter-ry; j <= ycenter+ry; j++){
          for(int k = zcenter - rz; k <= zcenter+rz; k++){
              int dx = xcenter - i;
              int dy = ycenter - j;
              int dz = zcenter - k;
              if((float)(dx*dx)/(rx*rx) + (float)(dy*dy)/(ry*ry) + (float)(dz*dz)/(rz*rz) <= 1){
                  t.cutVoxel(i, j, k);
              }
          }
      }
  }
}