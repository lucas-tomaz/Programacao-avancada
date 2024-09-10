#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "Sculptor.h"
/**
 * @class CutBox
 * @brief Classe que representa a demarcação de uma caixa que será removida entre os pontos x0, x1, y0, y1, z0 e z1. 
 * @param _x0 Número do ponto inicial da caixa em x.
 * @param _x1 Número do ponto final da caixa em x.
 * @param _y0 Número do ponto inicial da caixa em y.
 * @param _y1 Número do ponto final da caixa em y.
 * @param _z0 Número do ponto inicial da caixa em z.
 * @param _z1 Número do ponto final da caixa em z.
 */
class CutBox:public FiguraGeometrica
{
public:
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
    void draw(Sculptor &t);
private:
    int x0, x1, y0, y1, z0, z1;
};

#endif // CUTBOX_H