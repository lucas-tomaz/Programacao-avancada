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
private:
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
 * @brief Ativa cada voxel na posição em um intervalo específico.
  * @param x0,x1 Intervalo na coordenada x.
  * @param y0,y1 Intervalo na coordenada y.
  * @param z0,z1 Intervalo na coordenada z.
 */

  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

/**
 * @brief Desativa cada voxel na posição em um intervalo específico.
  * @param x0,x1 Intervalo na coordenada x.
  * @param y0,y1 Intervalo na coordenada y.
  * @param z0,z1 Intervalo na coordenada z.
 */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

/**
 * @brief Ativa todos os voxels que satisfazem a equação de uma esfera.
 * @param xcenter,ycenter,zcenter Coordenadas do centro da esfera.
 * @param radius Raio da esfera.
 */

  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

/**
 * @brief Desativa todos os voxels que satisfazem a equação de uma esfera.
 * @param xcenter,ycenter,zcenter Coordenadas do centro da esfera.
 * @param radius Raio da esfera.
 */

  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

/**
 * @brief Ativa todos os voxels que satisfazem a equação de uma elipsoide.
 * @param xcenter,ycenter,zcenter Coordenadas do centro da elipsoide.
 * @param rx,ry,rz Medidas dos semi-eixos da elipsoide nos eixos x, y, z.
 */

  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

/**
 * @brief Desativa todos os voxels que satisfazem a equação de uma elipsoide.
 * @param xcenter,ycenter,zcenter Coordenadas do centro da elipsoide.
 * @param rx,ry,rz Medidas dos semi-eixos da elipsoide nos eixos x, y, z.
 */

  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

/**
 * @brief Salva os dados do escultor em um arquivo OFF.
 * @param filename Nome do arquivo OFF.
 */

  void writeOFF(const char* filename);
};
