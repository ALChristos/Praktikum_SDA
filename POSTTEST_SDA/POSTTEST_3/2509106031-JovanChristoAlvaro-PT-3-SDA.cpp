//PAWCARE PETSHOP (BUKAN TANDA AI)
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; 

struct hewan{
    int id_hewan;
    string nama_hewan;
    int harga_hewan;
};

void swap_elemen(hewan* a, hewan* b){
    hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambah_hewan(hewan* data_hewan, int &banyak_hewan){
    string enter;

    if(banyak_hewan == MAX){
        cout<<"OVERFLOW: Hewan Di Toko Ini Sudah Penuh!!!"<<endl;
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

        cout<<"Hewan "<<data_hewan[banyak_hewan - 1].nama_hewan<<" Berhasil Ditambahkan!!!"<<endl;
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
            cout<<"\nID Hewan: "<<(data_hewan + i)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + i)->nama_hewan<<endl;
            cout<<"Harga Hewan: "<<(data_hewan + i)->harga_hewan<<endl;
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
            if((data_hewan + i)->nama_hewan == dicari){
                cout<<"\n========== Hewan Ditemukan =========="<<endl;
                cout<<"ID Hewan: "<<(data_hewan + i)->id_hewan<<endl;
                cout<<"Nama Hewan: "<<(data_hewan + i)->nama_hewan<<endl;
                cout<<"Harga Hewan: "<<(data_hewan + i)->harga_hewan<<endl;

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

            cout<<"Iterasi Ke-"<<iterasi<<": Cek Indeks Ke-"<<i<<" (ID Hewan: "<<(data_hewan + i)->id_hewan<<")"<<endl;
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
                cout<<"ID Hewan: "<<(data_hewan + i)->id_hewan<<endl;
                cout<<"Nama Hewan: "<<(data_hewan + i)->nama_hewan<<endl;
                cout<<"Harga Hewan: Rp "<<(data_hewan + i)->harga_hewan<<endl;
                ketemu = true;
                
                cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
                getline(cin, enter);
                break;
            }
        }
        
        if(!ketemu && offset + 1 < banyak_hewan && (data_hewan + offset + 1)->id_hewan == dicari){
            cout<<"\n========== DATA DITEMUKAN DI PALING AKHIR =========="<<endl;
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
                if((data_hewan + j)->nama_hewan > (data_hewan + j + 1)->nama_hewan){
                    swap_elemen((data_hewan + j), (data_hewan + j + 1));
                }
            }
        }

        cout<<"\n========== DATA HEWAN TERURUT =========="<<endl;
        for(int k = 0; k < banyak_hewan; k++){
            cout<<"\nID Hewan: "<<(data_hewan + k)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + k)->nama_hewan<<endl; 
            cout<<"Harga Hewan: "<<(data_hewan + k)->harga_hewan<<endl;
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
                if((data_hewan + j)->harga_hewan < (data_hewan + hewan_murah)->harga_hewan){
                    hewan_murah = j;
                }
            }

            if(hewan_murah != i){
                swap_elemen((data_hewan + i), (data_hewan + hewan_murah));
            }
        }

        cout<<"\n========== DATA HEWAN BERDASARKAN HARGA =========="<<endl;
        for(int a = 0; a < banyak_hewan; a++){
            cout<<"ID Hewan: "<<(data_hewan + a)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(data_hewan + a)->nama_hewan<<endl;
            cout<<"Harga Hewan: "<<(data_hewan + a)->harga_hewan<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }

        cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
        getline(cin, enter);
    }
}

void enqueue(hewan* data_hewan, int banyak_hewan, hewan* antrian, int &depan, int &posisi_belakang, int &jml_antrian){
    if(banyak_hewan <= 0) {
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(jml_antrian == MAX){ 
        cout<<"LOOSSHHH PAKDHE: Antrian Sudah Penuh!!! (Kapasitas Max: "<<MAX<<")"<<endl;
    } 
    else{
        int id_cari;
        cout<<"Masukan ID Hewan Yang Mau Antri: ";
        cin>>id_cari;
        cin.ignore();

        bool ada_di_toko = false;
        hewan hewan_ditemukan;
        
        for(int i = 0; i < banyak_hewan; i++){
            if((data_hewan + i)->id_hewan == id_cari){
                ada_di_toko = true;
                hewan_ditemukan = *(data_hewan + i); 
                break;
            }
        }

        if(!ada_di_toko){
            cout<<"GAGAL: Hewan Dengan ID "<<id_cari<<" TIDAK ADA Didalam Petshop!!!"<<endl;
        } 
        else{
            bool sudah_antri = false;
            if(jml_antrian > 0){
                for(int i = depan; i <= posisi_belakang; i++){
                    if((antrian + i)->id_hewan == id_cari){
                        sudah_antri = true;
                        break;
                    }
                }
            }

            if(sudah_antri){
                cout<<"GAGAL: Hewan "<<hewan_ditemukan.nama_hewan<<" SUDAH ADA Didalam Antrian!!!"<<endl;
            } 
            else{
                posisi_belakang++;
                *(antrian + posisi_belakang) = hewan_ditemukan; 
                jml_antrian++;
                
                cout<<"\nHewan "<<(antrian + posisi_belakang)->nama_hewan<<" Berhasil Masuk Antrian!!!"<<endl;
            }
        }
    }
    
    system("pause");
}

void dequeue(hewan* antrian, int &depan, int &belakang, int &jml_antrian, hewan* riwayat, int &index_riwayat, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(jml_antrian <= 0){ 
        cout<<"UNDERFLOW: Tidak Ada Antrian Saat Ini!!!"<<endl;
    } 
    else{
        hewan pasien = *(antrian + depan);
        cout<<"\n========== MEMANGGIL PASIEN =========="<<endl;
        cout<<"ID Hewan   : "<<pasien.id_hewan<<endl;
        cout<<"Nama Hewan : "<<pasien.nama_hewan<<endl;
        cout<<"=== Masuk Ke Ruang Pemeriksaan... ==="<<endl;

        if(index_riwayat >= MAX - 1){
            cout<<"Peringatan: Kapasitas riwayat (Stack) hampir penuh!"<<endl;
        } else {
            index_riwayat++;
            *(riwayat + index_riwayat) = pasien;
        }

        depan++;
        jml_antrian--;

        if (jml_antrian == 0){
            depan = 0; belakang = -1;
        }
    }

    system("pause");
}

void pop_riwayat(hewan* riwayat, int &index_riwayat, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(index_riwayat == -1){ 
        cout<<"UNDERFLOW: Belum Ada Riwayat Pemeriksaan!!!"<<endl;
    } 
    else{
        cout<<"Membatalkan Riwayat Pemeriksaan Terakhir Untuk Hewan: "<<(riwayat + index_riwayat)->nama_hewan<<endl;
        index_riwayat--; 
    }
    
    system("pause");
}

void peek_data(hewan* antrian, int depan, int jml_antrian, hewan* riwayat, int Index_riwayat, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else {
        cout<<"\n========== PEEK DATA =========="<<endl;
        
        cout<<"=== Antrian Terdepan ==="<<endl;
        if(jml_antrian > 0){
            cout<<"ID Hewan: "<<(antrian + depan)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(antrian + depan)->nama_hewan<<endl;
        } 
        else{
            cout<<"Antrian Terdepan Kosong!!!"<<endl;
        }

        cout<<"\n=== Riwayat Tindakan Terakhir ==="<<endl;
        if(Index_riwayat != -1){
            cout<<"ID Hewan: "<<(riwayat + Index_riwayat)->id_hewan<<endl;
            cout<<"Nama Hewan: "<<(riwayat + Index_riwayat)->nama_hewan<<endl;
        } 
        else{
            cout<<"Riwayat Tindakan Terakhir Kosong!!!"<<endl;
        }
    }

    system("pause");
}

void tampil_antrian(hewan* antrian, int depan, int belakang, int jml_antrian, int banyak_hewan) {
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(jml_antrian <= 0){
        cout<<"Antrian kosong!"<<endl;
    } 
    else{
        cout<<"\n========== DAFTAR ANTRIAN PEMERIKSAAN =========="<<endl;
        for(int i = depan; i <= belakang; i++){
            cout<<"Antrian ke-"<<(i - depan + 1)<<" | ID: "<<(antrian + i)->id_hewan<<" | Nama: "<<(antrian + i)->nama_hewan<<endl;
        }
    }
    
    system("pause");
}

void tampil_riwayat(hewan* riwayat, int index_riwayat, int banyak_hewan) {
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(index_riwayat == -1){
        cout<<"Riwayat Kosong!!!"<<endl;
    } 
    else{
        cout<<"\n========== RIWAYAT PEMERIKSAAN =========="<<endl;
        for(int i = index_riwayat; i >= 0; i--){                    
            cout<<"Riwayat | ID: "<<(riwayat + i)->id_hewan<<" | Nama: "<<(riwayat + i)->nama_hewan<<endl;
        }
    }
    
    system("pause");
}


int main(){
    hewan hwn[MAX]; 
    int banyak_hewan = 0;
    bool ulang = true;
    int pilihan;
    string enter;

    hewan antrian[MAX]; 
    int depan = 0, belakang = -1, jml_antrian = 0;

    hewan riwayat[MAX]; 
    int barisan_atas = -1;

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
        cout<<"7. Daftar Antrian Pemeriksaan"<<endl;
        cout<<"8. Panggil Pasien & Catat Tindakan"<<endl;
        cout<<"9. Batalkan Tindakan Terakhir"<<endl;
        cout<<"10. Lihat Pasien Depan & Tindakan Terakhir"<<endl;
        cout<<"11. Tampilkan Seluruh Antrian Pasien"<<endl;
        cout<<"12. Tampilkan Seluruh Riwayat Pemeriksaan"<<endl;
        cout<<"13. Keluar"<<endl;
        cout<<"==========================================================="<<endl;
        cout<<"Masukan Pilihan Anda: ";
        cin>>pilihan;

        cin.ignore();

        switch(pilihan){
            case 1: 
                tambah_hewan(hwn, banyak_hewan); 
                break;

            case 2: 
                semua_hewan(hwn, banyak_hewan); 
                break;

            case 3: 
                cari_nama_linear(hwn, banyak_hewan); 
                break;

            case 4: 
                cari_id_fibonacci(hwn, banyak_hewan); 
                break;

            case 5: 
                urutkan_nama_buble(hwn, banyak_hewan); 
                break;

            case 6: 
                urutkan_harga_selection(hwn, banyak_hewan); 
                break;

            case 7: 
                enqueue(hwn, banyak_hewan, antrian, depan, belakang, jml_antrian); 
                break;

            case 8: 
                dequeue(antrian, depan, belakang, jml_antrian, riwayat, barisan_atas, banyak_hewan);
                break;

            case 9: 
                pop_riwayat(riwayat, barisan_atas, banyak_hewan); 
                break;

            case 10: 
                peek_data(antrian, depan, jml_antrian, riwayat, barisan_atas, banyak_hewan); 
                break;

            case 11:
                tampil_antrian(antrian, depan, belakang, jml_antrian, banyak_hewan);
                break;

            case 12: 
                tampil_riwayat(riwayat, barisan_atas, banyak_hewan);
                break;

            case 13: 
                cout<<"Program Selesai :)"<<endl; 
                ulang = false; break;

            default:
                cout<<"Pilihan Tidak Ada!!!!"<<endl;
                cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama...";
                getline(cin, enter);
        }
    }

    return 0;
}