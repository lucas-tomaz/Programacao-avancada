#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Sculptor.h"

/**
 * @class FiguraGeometrica
 * @brief Classe responsável pelo desenhor de uma figura geometrica e sua alocação na memória.
 */

class FiguraGeometrica{
public:
    FiguraGeometrica();

  /**
 * @class virtual void draw
 * @brief Classe virtual pura responsável pelo desenho de uma figura geometrica nas dimensões e especificações de cor e transparência definidas na classe Sculptor.
 */

    virtual void draw(Sculptor &t)=0;

/**
 * @class virtual ~FiguraGeometrica
 * @brief Classe virtual destrutora usada para forçar a chamada do destrutor da subclasse.
 */

    virtual ~FiguraGeometrica(){};
  protected:
    float r, g, b, a;
};

#endif // FIGURAGEOMETRICA_H