#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class PutEllipsoid
 * @brief Classe que representa a demarcação de uma Elipse que será inserida nos pontos x,y e z terá raio rx, ry e rz. Além disso, a cor e a transparência da elipse será definida por r, g e b.
 * @param _xcenter Número do ponto central da elipse em x.
 * @param _ycenter Número do ponto central da elipse em y.
 * @param _zcenter Número do ponto central da elipse em z.
 * @param _rx Número do raio da esfera na direção x.
 * @param _ry Número do raio da esfera na direção y.
 * @param _rz Número do raio da esfera na direção z.
 * @param _r Valor da componente vermelha.
 * @param _g Valor da componente verde.
 * @param _b Valor da componente azul.
 * @param _a Valor da transparência.
 */
class PutEllipsoid:public FiguraGeometrica
{
public:
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz,float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
private:
    float xcenter, ycenter, zcenter, rx, ry, rz;
};

#endif // putEllipsoid_H