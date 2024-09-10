#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class PutSphere
 * @brief Classe que representa a demarcação de uma esfera que será inserida nos pontos x,y e z terá raio r. Além disso, a cor e a transparência da esfera será definida por r, g e b.
 * @param _xcenter Número do ponto central da esfera em x.
 * @param _ycenter Número do ponto central da esfera em y.
 * @param _zcenter Número do ponto central da esfera em z.
 * @param _radius Número do raio da esfera.
 * @param _r Valor da componente vermelha.
 * @param _g Valor da componente verde.
 * @param _b Valor da componente azul.
 * @param _a Valor da transparência.
 */
class PutSphere:public FiguraGeometrica
{
public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
private:
    float xcenter, ycenter, zcenter, radius;
};

#endif // PUTSPHERE_H