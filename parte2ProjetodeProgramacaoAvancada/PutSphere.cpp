#include "PutSphere.h"
#include <iostream>

PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a){
  this-> xcenter = _xcenter;
  this-> ycenter = _ycenter;
  this-> zcenter = _zcenter;
  this-> radius = _radius;
  this-> r = _r;
  this-> g = _g;
  this-> b = _b;
  this-> a = _a;
}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = xcenter - radius; i <= xcenter + radius; i++){
        for(int j = zcenter - radius; j <= zcenter + radius; j++){
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                int dx = xcenter - i;
                int dy = ycenter - j;
                int dz = zcenter - k;
                if(dx*dx + dy*dy + dz*dz <= radius*radius){
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}