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

struct node{
    hewan data;
    node* next;
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

        cout<<"\n========== PROSES PENCARIAN =========="<<endl; 
        while(fn > 1){
            if(offset + fn2 < banyak_hewan -1){ 
                i = offset + fn2;
            }
            else{
                i = banyak_hewan - 1; 
            }

            cout<<"Iterasi Ke-"<<iterasi<<": Cek Indeks Ke-"<<i<<" (ID Hewan: "<<(data_hewan + i)->id_hewan<<")"<<endl;
            iterasi += 1;

            if(dicari > (data_hewan + i)->id_hewan){ 
                fn = fn1;
                fn1 = fn2;
                fn2 = fn - fn1;
                offset = i;
            }
            else if(dicari < (data_hewan + i)->id_hewan){ 
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

void enqueue(hewan* data_hewan, int banyak_hewan, node*& data_depan, node*& data_belakang){
    if(banyak_hewan <= 0) {
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
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
            node* temp = data_depan;
        
            while(temp != NULL){
                if(temp->data.id_hewan == id_cari){
                    sudah_antri = true;
                    break;
                }
                temp = temp->next;
            }

            if(sudah_antri){
                cout<<"GAGAL: Hewan "<<hewan_ditemukan.nama_hewan<<" SUDAH ADA Didalam Antrian!!!"<<endl;
            } 
            else{

                node* nodeBaru = new node;
                nodeBaru->data = hewan_ditemukan;
                nodeBaru->next = NULL;

                if(data_depan == NULL){ 
                    data_depan = data_belakang = nodeBaru;
                } 
                else{
                    data_belakang->next = nodeBaru;
                    data_belakang = nodeBaru;
                }

                cout<<"\nHewan "<<data_belakang->data.nama_hewan<<" Berhasil Masuk Antrian!!!"<<endl;
            }
        }
    }

    system("pause");
}

void push(node*& data_atas, hewan data_pasien){
    node* nodeBaru = new node;
    nodeBaru->data = data_pasien;
    nodeBaru->next = data_atas; 
    data_atas = nodeBaru;
}

void dequeue(node*& data_depan, node*& data_belakang, node*& data_atas, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(data_depan == NULL){ 
        cout<<"UNDERFLOW: Tidak Ada Antrian Saat Ini!!!"<<endl;
    } 
    else{
        node* temp = data_depan;
        hewan pasien = temp->data;

        cout<<"\n========== MEMANGGIL PASIEN =========="<<endl;
        cout<<"ID Hewan   : "<<pasien.id_hewan<<endl;
        cout<<"Nama Hewan : "<<pasien.nama_hewan<<endl;
        cout<<"=== Masuk Ke Ruang Pemeriksaan... ==="<<endl;

        data_depan = data_depan->next;
        if(data_depan == NULL) data_belakang = NULL; 

        delete temp; 

        push(data_atas, pasien);
    }

    system("pause");
}

void pop_riwayat(node*& data_atas, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(data_atas == NULL){ 
        cout<<"UNDERFLOW: Belum Ada Riwayat Pemeriksaan!!!"<<endl;
    } 
    else{
        node* temp = data_atas;
        cout<<"Membatalkan Riwayat Pemeriksaan Terakhir Untuk Hewan: "<<temp->data.nama_hewan<<endl;
        
        data_atas = data_atas->next; 
        delete temp; 
    }
    system("pause");
}

void peek_data(node* data_depan, node* data_atas, int banyak_hewan){
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else {
        cout<<"\n========== PEEK DATA =========="<<endl;
        
        cout<<"=== Antrian Terdepan ==="<<endl;
        if(data_depan != NULL){
            cout<<"ID Hewan: "<<data_depan->data.id_hewan<<endl;
            cout<<"Nama Hewan: "<<data_depan->data.nama_hewan<<endl;
        } 
        else{
            cout<<"Antrian Terdepan Kosong!!!"<<endl;
        }

        cout<<"\n=== Riwayat Tindakan Terakhir ==="<<endl;
        if(data_atas != NULL){
            cout<<"ID Hewan: "<<data_atas->data.id_hewan<<endl;
            cout<<"Nama Hewan: "<<data_atas->data.nama_hewan<<endl;
        } 
        else{
            cout<<"Riwayat Tindakan Terakhir Kosong!!!"<<endl;
        }
    }
    system("pause");
}

void tampil_antrian(node* data_depan, int banyak_hewan) {
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(data_depan == NULL){
        cout<<"Antrian kosong!"<<endl;
    } 
    else{
        cout<<"\n========== DAFTAR ANTRIAN PEMERIKSAAN =========="<<endl;
        node* temp = data_depan;
        int no = 1;
        while(temp != NULL){
            cout<<"Antrian ke-"<<no<<" | ID: "<<temp->data.id_hewan<<" | Nama: "<<temp->data.nama_hewan<<endl;
            temp = temp->next;
            no++;
        }
    }
    system("pause");
}

void tampil_riwayat(node* data_atas, int banyak_hewan) {
    if(banyak_hewan <= 0){
        cout<<"Belum Ada Hewan Di Toko Ini!!!"<<endl;
    }
    else if(data_atas == NULL){
        cout<<"Riwayat Kosong!!!"<<endl;
    } 
    else{
        cout<<"\n========== RIWAYAT PEMERIKSAAN =========="<<endl;
        node* temp = data_atas;
        while(temp != NULL){
            cout<<"Riwayat | ID: "<<temp->data.id_hewan<<" | Nama: "<<temp->data.nama_hewan<<endl;
            temp = temp->next;
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

    node* antrian_depan = NULL;
    node* antrian_belakang = NULL;

    node* riwayat_teratas = NULL;

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
                enqueue(hwn, banyak_hewan, antrian_depan, antrian_belakang); 
                break;

            case 8: 
                dequeue(antrian_depan, antrian_belakang, riwayat_teratas, banyak_hewan);
                break;

            case 9: 
                pop_riwayat(riwayat_teratas, banyak_hewan); 
                break;

            case 10: 
                peek_data(antrian_depan, riwayat_teratas, banyak_hewan); 
                break;

            case 11:
                tampil_antrian(antrian_depan, banyak_hewan);
                break;

            case 12: 
                tampil_riwayat(riwayat_teratas, banyak_hewan);
                break;

            case 13: 
                cout<<"Program Selesai :)"<<endl; 
                ulang = false; break;

            default:
                cout<<"Pilihan Tidak Ada!!!!"<<endl;
                system("pause");
        }
    }

    return 0;
}