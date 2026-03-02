

#include <iostream>
using namespace std;

void tukar(int*a, int*b) {
    int tukar = *a;
    *a = *b;
    *b = tukar;
}

int main() {
    int x;
    int y;

    cout<<"Masukan Nilai X:";
    cin>>x;
    cout<<endl;

    cout<<"Masukan Nilai Y:";
    cin>>y;
    cout<<endl;

    cout<<endl;
    cout<<"Sebelum ditukar:"<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    tukar(&x, &y); 
    cout<<"\nSesudah ditukar:"<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    return 0;
}