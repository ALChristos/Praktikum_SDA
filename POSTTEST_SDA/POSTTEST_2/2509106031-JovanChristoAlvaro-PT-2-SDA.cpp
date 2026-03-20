//PAWCARE PETSHOP (BUKAN TANDA AI)

#include <iostream>
#include <string>
using namespace std;

struct hewan{
int id_hewan;
string nama_hewan;
int harga_hewan;
};

void tambah_hewan(hewan* data_hewan, int &banyak_hewan){
    string enter;

    if(banyak_hewan == 100){
        cout<<"Hewan Di Toko Ini Sudah Penuh!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        data_hewan[banyak_hewan].id_hewan = banyak_hewan + 1;
        
        cout<<"Masukan Nama Hewan: ";
        getline(cin, data_hewan[banyak_hewan].nama_hewan);
        cout<<"Masukan Harga Hewan: ";
        cin>>data_hewan[banyak_hewan].harga_hewan;

        banyak_hewan += 1;
        cin.ignore();

        cout<<"Hewan "<<data_hewan[banyak_hewan].nama_hewan<<" Berhasil Ditambahkan!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
}

void semua_hewan(hewan* data_hewan, int banyak_hewan){
    string enter;
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        for(int i = 0; i < banyak_hewan; i++){
            cout<<"\nID Hewan: "<<(data_hewan + i) -> id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + i) -> nama_hewan<<endl;
            cout<<"Harga Hewan: "<<(data_hewan + i) -> harga_hewan<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }

        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
        
    }
}

void cari_nama_linear(hewan* data_hewan, int banyak_hewan){
    string enter, dicari;
    bool ketemu = false;

    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        cout<<"Masukan Nama Hewan Yang Ingin Dicari: ";
        cin>>dicari;

        for(int i = 0; i < banyak_hewan; i++){
            if((data_hewan + i) -> nama_hewan == dicari){
                cout<<"\n========== Hewan Ditemukan =========="<<endl;
                cout<<"ID Hewan: "<<(data_hewan + i) -> id_hewan<<endl;
                cout<<"Nama Hewan: "<<(data_hewan + i) -> nama_hewan<<endl;
                cout<<"Harga Hewan: "<<(data_hewan + i) -> harga_hewan<<endl;

                ketemu = true;
            }
        }
        cin.ignore();
        
        if(ketemu != true){
            cout<<"Tidak Ada Nama Hewan Tersebut Didalam Toko Ini!!!"<<endl;
            cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
            getline(cin, enter);
        }
        
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);

    }
}

void cari_id_fibonacci(hewan* data_hewan, int banyak_hewan){
    string enter;
    int fn, fn1, fn2, i, dicari;
    int offset = -1;
    bool ketemu = false;
    int iterasi = 1; 

    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        cout<<"Masukan ID Hewan Yang Ingin Dicari: ";
        cin>>dicari;

        cin.ignore();

        fn2 = 0;
        fn1 = 1;
        fn = fn1 + fn2;

        while(fn < banyak_hewan){
            fn2 = fn1;
            fn1 = fn;
            fn = fn1 + fn2;
        }

        cout<<"\n========== PROSES PENCARIAN =========="<<endl; // <----- INI PROSES ITERASINYA: Jadi ketika target yang di cari(index hewannya) > dari nilai pada index titik potong(i)
                                                                // Maka fn akan menjadi fn1, dst (A). Begitupun dengan sebaliknya jika (target < i) maka (B)
        while(fn > 1){
            if(offset + fn2 < banyak_hewan -1){ // <-- Selama i(Titik Potong) tidak melebihi banyak hewan dari index 0 sampai n, Maka i nilainya akan terus bertambah
                i = offset + fn2;
            }
            else{
                i = banyak_hewan - 1; // <-- Kondisi ketika i lewat dari banyak hewan, maka titik potongnya langsung di taruh kebagian kanan array banyak hewan
            }

            cout<<"Iterasi Ke-"<<iterasi<<": Cek Indeks Ke-"<<i<<" (ID Hewan: "<<(data_hewan + i)->id_hewan << ")"<<endl;
            iterasi += 1;

            if(dicari > (data_hewan + i)->id_hewan){ // <--- (A) deret fibonacinya geser ke kiri 1 langkah
                fn = fn1;
                fn1 = fn2;
                fn2 = fn - fn1;
                offset = i;
            }
            else if(dicari < (data_hewan + i)->id_hewan){ // <-- (B) Deret Fibonaci geser ke kiri 2 langkah 
                fn = fn2;
                fn1 = fn1 - fn2;
                fn2 = fn - fn1;
            }
            else{
                cout<<"\n========== DATA DITEMUKAN =========="<<endl;
                cout<<"ID Hewan: " << (data_hewan + i)->id_hewan<<endl;
                cout<<"Nama Hewan: " << (data_hewan + i)->nama_hewan<<endl;
                cout<<"Harga Hewan: Rp " << (data_hewan + i)->harga_hewan<<endl;
                ketemu = true;
                
                cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
                getline(cin, enter);
                break;
            }
        }
        
        if(!ketemu && offset + 1 < banyak_hewan && (data_hewan + offset + 1)->id_hewan == dicari){
            cout<<"\n========== DATA DITEMUKAN DI PALING AKHIR ==========" << endl;
            cout<<"ID Hewan: "<<(data_hewan + offset + 1)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + offset + 1)->nama_hewan<<endl;
            cout<<"Harga Hewan: Rp "<<(data_hewan + offset + 1)->harga_hewan<<endl;
            ketemu = true;

            cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
            getline(cin, enter);
        }
        else if(ketemu == false){
            cout<<"\nTidak Ada Hewan Dengan ID: "<<dicari<<" Di Toko Ini!!!"<<endl;

            cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
            getline(cin, enter);
        }
    }
}

void urutkan_nama_buble(hewan* data_hewan, int banyak_hewan){
    string enter;

    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        for(int i = 0; i < banyak_hewan - 1; i++){
            for(int j = 0; j < banyak_hewan - 1 - i; j++){
                if((data_hewan + j) -> nama_hewan > (data_hewan + j + 1) -> nama_hewan){
                    hewan sementara = *(data_hewan + j);
                    *(data_hewan + j) = *(data_hewan + j + 1);
                    *(data_hewan + j + 1) = sementara;
                }
            }
        }

        cout<<"\n========== DATA HEWAN TERURUT =========="<<endl;
        for(int k = 0; k < banyak_hewan; k++){
            cout<<"\nID Hewan: "<<(data_hewan + k) -> id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + k) -> nama_hewan<<endl; 
            cout<<"Harga Hewan: "<<(data_hewan + k) -> harga_hewan<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
        
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
}

void urutkan_harga_selection(hewan* data_hewan, int banyak_hewan){
    string enter;
    int hewan_murah;

    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
    else{
        for(int i = 0; i < banyak_hewan - 1; i++){
            hewan_murah = i;

            for(int j = i + 1; j < banyak_hewan; j++){
                if((data_hewan + j) -> harga_hewan < (data_hewan + hewan_murah) -> harga_hewan){
                    hewan_murah = j;
                }
            }

            if(hewan_murah != i){
            hewan sementara = *(data_hewan + i);
            *(data_hewan + i) = *(data_hewan + hewan_murah);
            *(data_hewan + hewan_murah) = sementara;
            }
        }

        cout<<"\n========== DATA HEWAN BERDASARKAN HARGA =========="<<endl;
        for(int a = 0; a < banyak_hewan; a++){
            cout<<"ID Hewan: "<<(data_hewan + a) -> id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + a) -> nama_hewan<<endl;
            cout<<"Harga Hewan: "<<(data_hewan + a) -> harga_hewan<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }

        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
}

int main(){
    hewan hwn[100];
    int banyak_hewan = 0;
    bool ulang = true;
    char pilihan;
    string enter;

    while(ulang){
        cout<<"\n==========================================================="<<endl;
        cout<<"==================== PAWCARE PETSHOP ======================"<<endl;
        cout<<"==========================================================="<<endl;
        cout<<"1. Tambah Hewan Baru"<<endl;
        cout<<"2. Lihat Seluruh Hewan Di Shop"<<endl;
        cout<<"3. Cari Hewan Berdasarkan Nama"<<endl;
        cout<<"4. Cari Hewan Berdasarkan ID"<<endl;
        cout<<"5. Urutkan Hewan Berdasarkan Nama"<<endl;
        cout<<"6. Urutkan Hewan Berdasarkan Harga"<<endl;
        cout<<"7. Keluar"<<endl;
        cout<<"==========================================================="<<endl;
        cout<<"Masukan Pilihan Anda: ";
        cin>>pilihan;

        cin.ignore();

        switch(pilihan){
            case '1':
                tambah_hewan(hwn, banyak_hewan);
                break;

            case '2':
                semua_hewan(hwn, banyak_hewan);
                break;

            case '3':
                cari_nama_linear(hwn, banyak_hewan);
                break;

            case '4':
                cari_id_fibonacci(hwn, banyak_hewan);
                break;

            case '5':
                urutkan_nama_buble(hwn, banyak_hewan);
                break;

            case '6':
                urutkan_harga_selection(hwn, banyak_hewan);
                break;

            case '7':
                cout<<"Program Selesai :)"<<endl;
                ulang = false;
                break;

            default:
                cout<<"Pilihan Tidak Ada!!!!"<<endl;
                cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
                getline(cin, enter);
        }
    }
}