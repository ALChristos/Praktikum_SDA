//Array & Pointer - Operasi Dasar

#include <iostream>
using namespace std;

void balik_array(int* arr, int n) {
    int tukar;
    for (int i = 0; i < n / 2; i++) {
        tukar = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tukar;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array Sebelum Dibalik: ";
    for (int i = 0; i < n; i++) {
        cout<<prima[i]<<" ";
    }
    cout<<endl;

    cout<<endl;
    cout<<"Alamat Memori:"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Alamat Array"<<"["<<i<<"]"<<" = "<<&prima[i]<<endl;
    }
    cout<<endl;

    balik_array(prima, n);
    cout<<"Array Sesudah Dibalik: ";
    for (int i = 0; i < n; i++) {
        cout<<prima[i]<<" ";
    }
    cout<<endl;

    return 0;
}