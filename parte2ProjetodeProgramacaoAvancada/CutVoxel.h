#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class CutVoxel
 * @brief Classe que representa um voxel e suas características de localização. Trata-se da desativação do voxel na posição especificada em x, y e z.
 * @param _x Número do voxels na dimensão x.
 * @param _y Número do voxel na dimensão y.
 * @param _z Número do voxels na dimensão z.
 */
class CutVoxel: public FiguraGeometrica
{
public:
    CutVoxel(int _x, int _y, int _z);
    void draw(Sculptor &t);
private:
    float x, y, z;
};

#endif // CUTVOXEL_H