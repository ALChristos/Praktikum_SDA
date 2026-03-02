// Struct + Array Data Mahasiswa

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    string ipk;
};

int main(){
    mahasiswa mahasigma[5];
    for(int i = 0; i < 5; i++){
        cout<<"Data Mahasiswa Ke-"<<i + 1<<endl;
        cout<<"Nama Mahasiswa: ";
        cin>>mahasigma[i].nama;
        cout<<"NIM Mahasiswa: ";
        cin>>mahasigma[i].nim;
        cout<<"IPK Mahasiswa: ";
        cin>>mahasigma[i].ipk;
        
        cout<<endl;
    }
    
    int IPK_max = 0;
    for(int i = 0; i < 5; i++){
        if(mahasigma[i].ipk > mahasigma[IPK_max].ipk){
            IPK_max = i;
        }
    }

    cout<<"=========================================================================================="<<endl;
    cout<<endl;
    cout<<"Mahasiswa Dengan NIM Tertinggi:"<<endl;
    cout<<"Nama Mahasiswa: "<<mahasigma[IPK_max].nama<<endl;
    cout<<"NIM Mahasiswa: "<<mahasigma[IPK_max].nim<<endl;
    cout<<"IPK Mahasiswa: "<<mahasigma[IPK_max].ipk<<endl;

    return 0;
}