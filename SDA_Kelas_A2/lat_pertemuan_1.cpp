// #include <iostream>
// using namespace std;

// int main(){
//     int arr[5] = {1,2,3,100,5};
//     for(int i = 0; i < 5; i++){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }


//POINTER
// #include <iostream>
// using namespace std;

// int main() {
// int angka = 50;
// int *pAngka;
// // Pointer menyimpan alamat variabel angka
// pAngka = &angka;
// // Menampilkan nilai dan alamat
// cout << "Nilai variabel angka : " << angka << endl;
// cout << "Alamat variabel angka : " << &angka << endl;
// cout << "Alamat yang disimpan pointer : " << pAngka << endl;
// cout << "Nilai yang diakses melalui pointer : " << *pAngka << endl;
// return 0;
// }


// #include <iostream>
// using namespace std;
// struct alamat
// {
// string nama;
// long int nomor_rumah;
// string nama_jalan;
// string kota;
// long kode_pos;
// };
// int main(){
// alamat alamat_saya;
// alamat_saya.nama = "Budi";
// alamat_saya.nomor_rumah = 12;
// cout << "Nama: " << alamat_saya.nama << endl;
// cout << "Nomor Rumah: " << alamat_saya.nomor_rumah << endl;
// return 0;
// }



// #include <iostream>
// using namespace std;
// struct Mahasiswa {
// string nama;
// int nim;
// };
// int main() {
// Mahasiswa mhs1;
// Mahasiswa *mhsPtr = &mhs1;
// mhs1.nama = "Yunjin";
// mhs1.nim = 321;
// cout << mhs1.nama << " - " << mhs1.nim << endl;
// mhsPtr->nama = "Chawon";
// mhsPtr->nim = 573;
// cout << mhs1.nama << " - " << mhs1.nim << endl;
// cout << mhsPtr->nama << " - " << mhsPtr->nim << endl;
// return 0;
// }