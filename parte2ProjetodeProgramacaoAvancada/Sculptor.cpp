#include "Sculptor.h"
#include <iostream>
#include <fstream>

using namespace std;

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
                    file << "4 " << baseIndex << " " << baseIndex + 3 << " " << baseIndex + 2 << " " << baseIndex + 1 << " "
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