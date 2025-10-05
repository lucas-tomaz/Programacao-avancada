#include <iostream>

using namespace std;

int main(){
    //int i = 7;

   // int *pti = &i;

   // cout << i << endl;

    //*pti = 111;

    //cout << i << ' ' << *pti << endl;

    //O ponteiro aponta para o endereço de memória para da variável i;
    // a variável i é inicializada com o valor 7
    //depois é feito a modificação para que seja armazenada o valor 111 na posição de memória no qual pti aponta, ou seja, na variável i.

    int i = 7, j = 8;

    int* ptr = nullptr;

    cout << "\nVALORES INICIAIS:" <<  endl;
    cout << "i=" << i << "\t\t j = " << j << "\t\t ptr = " << ptr << endl;
    cout << "end(i)=" << &i << "\t\t end(j) = " << &j << "\t\t end(ptr) = " << &ptr << endl;

    //ponteiro para j:
    ptr = &j;

    //Armazenar 111 na posição de memória no qual ptr aponta
    *ptr = 111;

    cout << "\nPRIMEIRA:" <<  endl;
    cout << "i=" << i << "\t\t j = " << j << "\t\t ptr = " << ptr << endl;
    cout << "end(i)=" << &i << "\t\t end(j) = " << &j << "\t\t end(ptr) = " << &ptr << endl;

    *ptr++;

    *ptr = 222;

    cout << "\nSEGUNDA:" <<  endl;
    cout << "i=" << i << "\t\t j = " << j << "\t\t ptr = " << ptr << endl;
    cout << "end(i)=" << &i << "\t\t end(j) = " << &j << "\t\t end(ptr) = " << &ptr << endl;
}
