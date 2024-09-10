/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE
    CENTRO DE TECNOLOGIA - DEPARTAMENTO DE ENGENHARIA ELÉTRICA
    PROGRAMAÇÃO AVANÇADA - 2023.2/Docente: Agostinho Brito.
    Autor: Lucas Tomaz de Moura - Matrícula:20230022650

    DESCRIÇÃO: 
      Projeto da disciplina de Programação Avançada como requisito para obtenção da nota referente a segunda unidade do componente curricular. O projeto consiste em um programa capaz de gerar arquivos gráficos para visualização de componentes 3D. Tem como resultado final a criação de um arquivo do tipo ".off" no qual é submetidos em plataformas de visuação 3D. Neste arquivo estão a representação gráfica de uma árvore, um submarino e a representação do planeta saturno. Todas as representações estão disponíveis para o usuário visualizar em 3D nos arquivos nomeados com as respectivas figuras.
*/

#include <iostream>
#include "sculptor.h"
//incluir #include "sculptor.h"
int main() {
  //cria um objeto do tipo sculptor chamado figura com dimensões de 70x70x70:
  Sculptor figuras(70, 70, 70);
  //Sculptor saturno(70, 70, 70);
  /*
//planeta saturno:
  //define a cor da esfera do arco que envolve o planeta saturno:
  saturno.setColor(0.2156, 0.2431, 0.2627, 1.0);
  //cria um esfera de tamanho 20:
  saturno.putSphere(30, 30, 30, 20);
  //remove a parte superior da esfera:
  saturno.cutBox(10, 50, 30, 51, 10, 50);
  //remove a parte abaixo da esfera:
  saturno.cutBox(10, 50, 10, 27, 10, 50);
  //remove uma esfera para formar o arco:
  saturno.cutSphere(30, 30, 30, 18);
  //define a cor do planeta saturno:
  saturno.setColor(1.0, 0.64, 0, 1.0);
  //cria uma esfera que esteja contida no intervalo do arco:
  saturno.putSphere(30, 29, 30, 15);
  */
  /*
//árvore:

  // define a cor do tronco:
  figuras.setColor(0.58, 0, 0.29,1.0); // roxo.
  
  // ativa os voxels na faixa de [x,y,z] e cria o tronco.
  figuras.putBox(5,6,5,9,5,6);
  
  //define a cor das folhas da árvore:
  figuras.setColor(0, 1.0, 0, 1.0);
  
  //define uma esfera para ser as folhas da árvore:
  figuras.putSphere(5,14, 5, 5);
  */

//submarino:
  //definição de cor da ellipsoid do submarino:
  figuras.setColor(1.0, 1.0, 1.0, 1.0);
  
  //definição das dimensões da ellipsoid:
  figuras.putEllipsoid(35, 35, 35, 10.0, 5.0, 4.0);

  //realiza um "corte" no submarino nas dimensões especificadas.
  figuras.cutEllipsoid(35, 35, 35, 10.0, 4.0, 3.0);
  
  //define a cor da ellipsoid que será o vidro do submarino:
  figuras.setColor(0, 0, 1.0, 1.0);
  
  //adiciona uma ellipsoide que será o vidro do submarino:
  figuras.putEllipsoid(35, 35, 35, 10.0, 4.0, 3.0);

  //define a cor do mastro do submarino:
  figuras.setColor(1.0, 1.0, 0, 1.0);

  //define as dimensões do mastro do submarino:
  figuras.putBox(35, 35, 40, 45, 35, 35);

  //define a cor da extremidade do mastro do submarino:
  figuras.setColor(1.0, 0, 0, 1.0);

  //define a cor do último voxel que está no topo do mastro do submarino:
  figuras.putVoxel(35, 45, 35);

  // grava as esculturas digitais no arquivo "sculptor.off"
  figuras.writeOFF("submarino.off");
}