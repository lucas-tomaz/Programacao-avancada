#include <iostream>

using namespace std;

int main(){

        float arr[10];
        float *ptr;

        ptr = arr;

        for(int i=0; i < 10; i++){
            arr[i] = 1.0/(i + 1);
        }

        for(int i = 0; i<10; i++){
            cout << *(ptr + i) << " ";
        }
        cout << "\n";

         for(int i=0; i < 10; i++){
            arr[i] = 2.0/(i + 1);
        }

        for(int i = 0; i<10; i++){
            cout << ptr[i] << " ";
        }
        cout << "\n";
}