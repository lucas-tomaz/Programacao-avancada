#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class CutSphere
 * @brief Classe que representa a demarcação de uma esfera que será removida nos pontos x,y e z terá raio r.
 * @param _xcenter Número do ponto central da esfera em x.
 * @param _ycenter Número do ponto central da esfera em y.
 * @param _zcenter Número do ponto central da esfera em z.
 * @param _radius Número do raio da esfera.
 */
class CutSphere:public FiguraGeometrica
{
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    void draw(Sculptor &t);
private:
    float xcenter, ycenter, zcenter, radius;
};

#endif // CUTSPHERE_H