#include <iostream>

using namespace std;

int main(){

 // double* x;

  //x = new double[10];

 // x[3] = 2.5;

  //cout << x[5];

 // delete[] x;

    int x = 4;
    int y = 4;
    int i,j = 0;

    int** matriz;

    matriz = new int* [x];
    
    for(i = 0; i < x; i++){
        matriz[i] = new int[y];
        for(j = 0; j < y; j++){
            matriz[i][j] = 10*(i + 1) + (j+1);
        }
    }

    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    cout << endl;
    
    for (i = 0; i < x; i++) {
        delete[] matriz[i];
    }

    delete[] matriz;

    return 0;
}