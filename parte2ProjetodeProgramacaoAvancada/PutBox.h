#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class PutBox
 * @brief Classe que representa a demarcação de uma caixa que será demarcada entre os pontos x0, x1, y0, y1, z0 e z1. Além disso, a cor e a transparência da esfera será definida por r, g e b.
 * @param _x0 Número do ponto inicial da caixa em x.
 * @param _x1 Número do ponto final da caixa em x.
 * @param _y0 Número do ponto inicial da caixa em y.
 * @param _y1 Número do ponto final da caixa em y.
 * @param _z0 Número do ponto inicial da caixa em z.
 * @param _z1 Número do ponto final da caixa em z.
 * @param _r Valor da componente vermelha.
 * @param _g Valor da componente verde.
 * @param _b Valor da componente azul.
 * @param _a Valor da transparência.
 */
class PutBox:public FiguraGeometrica
{
public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1,float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
private:
    int x0, x1, y0, y1, z0, z1;
};

#endif // PUTBOX_H