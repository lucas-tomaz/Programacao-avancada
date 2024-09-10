#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <cstdlib>

/**
 * @struct Voxel
 * @brief Classe que relaciona um voxel e suas características de cor, visibilidade e transparência.
 */

struct Voxel {
  float r, g, b; ///< Cores na faixa de vermelho, verde e azul do voxel.
  float a;       ///< Transparência do voxel.
  bool show;     ///< Se o voxel será visível ou não.
};

/**
 * @class Sculptor
 * @brief Classe que representa o aspecto de alocação de um objeto 3D.
 */

class Sculptor {
protected:
  Voxel ***v;    ///< Matriz 3D
  int nx, ny, nz; ///< Dimensões
  float r, g, b, a; ///< Cor atual de desenho

public:

/**
 * @brief Construtor da classe Sculptor.
 * @param _nx Número de voxels na dimensão x.
 * @param _ny Número de voxels na dimensão y.
 * @param _nz Número de voxels na dimensão z.
 */
  Sculptor(int _nx, int _ny, int _nz);

/**
 * @brief Destrutor da classe Sculptor.
 */
  ~Sculptor();

/**
 * @brief Define a cor atual de desenho.
 * @param r Valor da componente vermelha.
 * @param g Valor da componente verde.
 * @param b Valor da componente azul.
 * @param alpha Valor da transparência.
 */
  void setColor(float r, float g, float b, float alpha);

/**
 * @brief Ativa um voxel na posição (x, y, z).
 * @param x Coordenada x do voxel.
 * @param y Coordenada y do voxel.
 * @param z Coordenada z do voxel.
 */
  void putVoxel(int x, int y, int z);

/**
 * @brief Desativa um voxel na posição (x, y, z).
 * @param x Coordenada x do voxel.
 * @param y Coordenada y do voxel.
 * @param z Coordenada z do voxel.
 */

  void cutVoxel(int x, int y, int z);
/**
 * @brief Salva os dados do escultor em um arquivo OFF.
 * @param filename Nome do arquivo OFF.
 */

  void writeOFF(const char* filename);
};
#endif
