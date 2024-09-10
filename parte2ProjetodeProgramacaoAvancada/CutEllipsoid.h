#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class CutEllipsoid
 * @brief Classe que representa a demarcação de uma Elipse que será removida nos pontos x,y e z terá raio rx, ry e rz.
 * @param _xcenter Número do ponto central da elipse em x.
 * @param _ycenter Número do ponto central da elipse em y.
 * @param _zcenter Número do ponto central da elipse em z.
 * @param _rx Número do raio da esfera na direção x.
 * @param _ry Número do raio da esfera na direção y.
 * @param _rz Número do raio da esfera na direção z.
 */
class CutEllipsoid:public FiguraGeometrica
{
public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    void draw(Sculptor &t);
private:
    float xcenter, ycenter, zcenter, rx, ry, rz;
};

#endif // cutEllipsoid_H