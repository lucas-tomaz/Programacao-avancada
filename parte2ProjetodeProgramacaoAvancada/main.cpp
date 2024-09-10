
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "figurageometrica.h"
#include "Sculptor.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"

int main(){
    Sculptor *t1;
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;

    fin.open("fonte.txt");

    if(!fin.is_open()){
        return 0;
    }
    std::string t;
    while(fin.good()){
        fin >> t;
        if(fin.good()){
            if(t.compare("dim") == 0){
                int nx, ny, nz;
                fin >> nx >> ny >> nz;
                t1 = new Sculptor(nx, ny, nz);
            }
           else if(t.compare("putvoxel") == 0){
               int x, y, z; 
                float r, g, b, a;
               fin >> x >> y >> z >> r >> g >> b >> a;
               figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
           }
          else if(t.compare("cutvoxel") == 0){
               int x, y, z;
               fin >> x >> y >> z;
               figs.push_back(new CutVoxel(x, y, z));
           }
          else if(t.compare("putbox") == 0){
              int x0, x1, y0, y1, z0, z1; 
              float r, g, b, a;
               fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
               figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
           }
          else if(t.compare("cutbox") == 0){
              int x0, x1, y0, y1, z0, z1;
               fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
               figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
           }
          else if(t.compare("putsphere") == 0){
              int xcenter, ycenter, zcenter, radius;
              float r, g, b, a;
              fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
              figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
           }
          else if(t.compare("cutsphere") == 0){
              int xcenter, ycenter, zcenter, radius;
              fin >> xcenter >> ycenter >> zcenter >> radius;
              figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
           }
          else if(t.compare("putellipsoid") == 0){
             int xcenter, ycenter, zcenter, rx, ry, rz;
             float r, g, b, a;
             fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
              figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
           }
          else if(t.compare("cutellipsoid") == 0){
             int xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a;
             fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
              figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
           }
       }
    }
    for(int i=0; i<figs.size(); i++){
        figs[i]->draw(*t1);
    }

    t1->writeOFF((char*)"figura.off");
    delete t1;
    for(int i=0; i<figs.size(); i++){
        delete figs[i];
    }

    std::cout << "fim!\n";
    return 0;
}