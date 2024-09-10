#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class PutVoxel
 * @brief Classe que representa um voxel e suas características de localização, cor e transparência. Trata-se da ativação do voxel na posição especificada em x, y e z.
 * @param _x Número do voxels na dimensão x.
 * @param _y Número do voxel na dimensão y.
 * @param _z Número do voxels na dimensão z.
 * @param _r Valor da componente vermelha.
 * @param _g Valor da componente verde.
 * @param _b Valor da componente azul.
 * @param _a Valor da transparência.
 */
class   PutVoxel:public FiguraGeometrica
{
public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
private:
    float x, y, z;
};

#endif // PUTVOXEL_H