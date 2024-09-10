#include "CutSphere.h"
#include <iostream>

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
  this-> xcenter = _xcenter;
  this-> ycenter = _ycenter;
  this-> zcenter = _zcenter;
  this-> radius = _radius;
}

void CutSphere::draw(Sculptor &t){
    t.setColor(r, g, b, a);
  for(int i = xcenter - radius; i <= xcenter+radius; i++){
      for(int j = xcenter - radius; j <= xcenter+radius; j++){
          for(int k = xcenter-radius; k <= xcenter+radius; k++){
              int dx = xcenter - i;
              int dy = ycenter - j;
              int dz = zcenter - k;
              if(dx*dx + dy*dy + dz*dz <= radius*radius){
                  t.cutVoxel(i, j, k);
              }
          }
      }
  }
}