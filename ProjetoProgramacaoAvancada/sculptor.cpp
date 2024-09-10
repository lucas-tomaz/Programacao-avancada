#include "sculptor.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];
    for(int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    if(x < 0 || x >= nx || y < 0 || y >= ny || z < 0 || z >= nz){
        return;
    }
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x < 0 || x >= nx || y < 0 || y >= ny || z < 0 || z >= nz){
        return;
    }
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                putVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                int dx = xcenter - i;
                int dy = ycenter - j;
                int dz = zcenter - k;
                if(dx*dx + dy*dy + dz*dz <= radius*radius){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                int dx = xcenter - i;
                int dy = ycenter - j;
                int dz = zcenter - k;
                if(dx*dx + dy*dy + dz*dz <= radius*radius){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                float dx = xcenter - i;
                float dy = ycenter - j;
                float dz = zcenter - k;
                if((dx*dx)/(rx*rx) + (dy*dy)/(ry*ry) + (dz*dz)/(rz*rz) <= 1){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                int dx = xcenter - i;
                int dy = ycenter - j;
                int dz = zcenter - k;
                if((float)(dx*dx)/(rx*rx) + (float)(dy*dy)/(ry*ry) + (float)(dz*dz)/(rz*rz) <= 1){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
  std::cout << "Escrevendo objeto" << std::endl;
    std::ofstream file(filename);
    if (!file.is_open()){
        std::cerr << "Erro na abertura do arquivo OFF " << filename << std::endl;
        return;
    }

    file << "OFF" << std::endl;
    int countVoxels = 0;

   
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].show){
                    countVoxels++;
                }
            }
        }
    }

    file << countVoxels * 8 << " " << countVoxels * 6 << " 0" << std::endl;
 
  file << std::fixed;
    // Escrever os vertices dos voxels.
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].show){
                    file << i << " " << j << " " << k << std::endl;
                    file << i << " " << j + 1 << " " << k << std::endl;
                    file << i + 1 << " " << j + 1 << " " << k << std::endl;
                    file << i + 1 << " " << j << " " << k << std::endl;
                    file << i << " " << j << " " << k + 1 << std::endl;
                    file << i << " " << j + 1 << " " << k + 1 << std::endl;
                    file << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
                    file << i + 1 << " " << j << " " << k + 1 << std::endl;
                }
            }
        }
    }

    // Escrever as faces dos voxels
    int voxelIndex = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].show){
                    int baseIndex = voxelIndex * 8;
                    file << "4 " <<  << " " << baseIndex + 3 << " " << baseIndex + 2 << " " << baseIndex + 1 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 4 << " " << baseIndex + 5 << " " << baseIndex + 6 << " " << baseIndex + 7 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 5 << " " << baseIndex + 4 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 2 << " " << baseIndex + 3 << " " << baseIndex + 7 << " " << baseIndex + 6 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 6 << " " << baseIndex + 5 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex << " " << baseIndex + 4 << " " << baseIndex + 7 << " " << baseIndex + 3 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    voxelIndex++;
                }
            }
        }
    }

    file.close();
 std::cout << "Finalizada a escrita do objeto" << std::endl;
}
