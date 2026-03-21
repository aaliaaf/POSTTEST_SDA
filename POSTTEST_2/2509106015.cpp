#include <iostream>
#include <string>
#include <cstdlib> 
#include "../table/text_table.h"
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    string status;
    string calonPemilik;
};

void tukarData(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tungguEnter() {
    cout << "\nTekan enter untuk lanjut...";
    cin.ignore();
    cin.get();
}

void bersihkanLayar() {
    system("cls");
}
void menampilkanDataHewan(Hewan* data, int jumlah) {
    cout << "==================================" << endl;
    cout << "|   DAFTAR HEWAN YANG TERSEDIA   |" << endl;
    cout << "==================================" << endl;
    TextTable tabel('-', '|', '+');
    string judul[5] = {"ID", "Nama", "Jenis", "Status", "Calon Pemilik"};
    for(int i = 0; i < 5; i++) {
        tabel.add(judul[i]);
    }
    tabel.endOfRow();
    
    for (int i = 0; i < jumlah; i++) {
        tabel.add(to_string((data + i)->id));
        tabel.add((data + i)->nama);
        tabel.add((data + i)->jenis);
        tabel.add((data + i)->status);
        tabel.add((data + i)->calonPemilik);
        tabel.endOfRow();
    }
    cout << tabel;
    tungguEnter();
}
void menambahkanHewanBaru(Hewan*& data, int& jumlah) {
    cout << "==================================" << endl;
    cout << "|    MENU TAMBAH HEWAN ADOPSI    |" << endl;
    cout << "==================================" << endl;
    
    Hewan* dataBaru = new Hewan[jumlah + 1];
    for (int i = 0; i < jumlah; i++) {
        dataBaru[i] = data[i];
    }

    cout << "ID Hewan         : "; cin >> dataBaru[jumlah].id;
    cout << "Nama Hewan       : "; cin >> dataBaru[jumlah].nama;
    cout << "Jenis Hewan      : "; cin >> dataBaru[jumlah].jenis;
    cout << "Status (Tersedia/Teradopsi): "; cin >> dataBaru[jumlah].status;
    cout << "Calon Pemilik    : "; cin >> dataBaru[jumlah].calonPemilik;

    delete[] data;
    data = dataBaru;
    jumlah++;

    cout << "\nData hewan berhasil ditambahkan!" << endl;
    tungguEnter();
}
void updateStatus(Hewan* data, int jumlah) {
    cout << "==================================" << endl;
    cout << "|   UPDATE STATUS HEWAN ADOPSI   |" << endl;
    cout << "==================================" << endl;
    
    int id;
    cout << "Masukkan ID Hewan: "; cin >> id;
    
    int idx = -1;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].id == id) {
            idx = i;
            break;
        }
    }
    
    if (idx == -1) {
        cout << "\nID hewan tersebut tidak ditemukan!" << endl;
        tungguEnter();
        return;
    }
    
    cout << "\nData Ditemukan:" << endl;
    cout << "ID: " << data[idx].id << ", Nama: " << data[idx].nama << endl;
    cout << "Status Saat Ini: " << data[idx].status << endl;
    cout << "Calon Pemilik Saat Ini: " << data[idx].calonPemilik << endl;
    
    cout << "\nUpdate Status Baru (Tersedia/Teradopsi): "; cin >> data[idx].status;
    cout << "Update Calon Pemilik: "; cin >> data[idx].calonPemilik;
    
    cout << "\nStatus hewan berhasil diupdate!" << endl;
    tungguEnter();
}
void hapusHewan(Hewan*& data, int& jumlah) {
    cout << "==================================" << endl;
    cout << "|      HAPUS HEWAN TERADOPSI     |" << endl;
    cout << "==================================" << endl;

    int id;
    cout << "Masukkan ID hewan yang akan dihapus: "; cin >> id;
    
    int idx = -1;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].id == id) {
            idx = i;
            break;
        }
    }
    
    if (idx == -1) {
        cout << "\nID hewan tersebut tidak ditemukan!" << endl;
        tungguEnter();
        return;
    }
    
    cout << "\nData yang akan dihapus:" << endl;
    cout << "ID: " << data[idx].id << ", Nama: " << data[idx].nama << endl;
    cout << "Status: " << data[idx].status << endl;
    
    char konfirmasi;
    cout << "\nYakin ingin menghapus? (y/n): "; cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        Hewan* dataBaru = new Hewan[jumlah - 1];
        
        int j = 0;
        for (int i = 0; i < jumlah; i++) {
            if (i != idx) {
                dataBaru[j] = data[i];
                j++;
            }
        }
        
        delete[] data;
        data = dataBaru;
        jumlah--;
        
        cout << "\nHewan berhasil dihapus!" << endl;
    } else {
        cout << "\nPenghapusan dibatalkan." << endl;
    }
    
    tungguEnter();
}
//Cara Kerja Linear Search:
// 1. Mulai dari index pertama (i = 0)
// 2. Cek apakah data[i].nama sama dengan namaCari
// 3. Jika sama maka kembalikan index i (data ditemukan)
// 4. Jika tidak sama maka lanjut ke index berikutnya (i++)
// 5. Ulangi sampai semua data diperiksa (i < jumlah)
// 6. Jika tidak ditemukan maka kembalikan -1

// Iterasi (Mencari "Luna" dari 5 data):
// Iterasi 1: i=0 > data[0].nama = "Kiko" bukan "Luna" maka Lanjut
// Iterasi 2: i=1 > data[1].nama = "Bruno" bukan "Luna" maka Lanjut
// Iterasi 3: i=2 > data[2].nama = "Mochi" bukan "Luna" maka Lanjut
// Iterasi 4: i=3 > data[3].nama = "Luna" sama dengan "Luna" maka ditemukan lalu Return 3
int linearSearchHewan(Hewan* data, int jumlah, string namaCari) {
    for (int i = 0; i < jumlah; i++) {     
        if (data[i].nama == namaCari) {  
            return i;                    
        }
    }
    return -1;                        
}
int fibonacciSearchHewan(Hewan* data, int jumlah, int idCari) {
    int FIB2 = 0;
    int FIB1 = 1;
    int FIB = FIB2 + FIB1;
    int iterasi = 1;
    while (FIB < jumlah) {
        FIB2 = FIB1;
        FIB1 = FIB;
        FIB = FIB2 + FIB1;
    }

    int offset = -1;

    while (FIB > 1) {
        int idx = (offset + FIB2 < jumlah - 1) ? offset + FIB2 : jumlah - 1;
        
        if ((data + idx)->id < idCari) {
            FIB = FIB1;
            FIB1 = FIB2;
            FIB2 = FIB - FIB1;
            offset = idx;
        } else if ((data + idx)->id > idCari) {
            FIB = FIB2;
            FIB1 = FIB1 - FIB2;
            FIB2 = FIB - FIB1;
        } else {
            return idx;
        }
    }

    if (FIB1 && (offset + 1 < jumlah) && (data + offset + 1)->id == idCari) {
        return offset + 1;
    }

    return -1;
}
void mengurutkanNamaHewan(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((data + j)->nama > (data + j + 1)->nama) {
                tukarData(&data[j], &data[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z)!" << endl;
}
void mengurutkanStatus(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int idxTarget = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((data + j)->status < (data + idxTarget)->status) {
                idxTarget = j;
            }
        }
        if (idxTarget != i) {
            tukarData(&data[i], &data[idxTarget]);
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Status!" << endl;
}
void mengurutkanID(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((data + j)->id > (data + j + 1)->id) {
                tukarData(&data[j], &data[j + 1]);
            }
        }
    }
}
void tampilanMenu() {
    cout << "==============================================" << endl;
    cout << "|      MENU PROGRAM ADOPSI HEWAN             |" << endl;
    cout << "==============================================" << endl;
    cout << "|1. Tampilkan Semua Data Hewan               |" << endl;
    cout << "|2. Tambah Data Hewan Baru                   |" << endl;
    cout << "|3. Linear Search (Mencari Berdasarkan Nama) |" << endl;
    cout << "|4. Fibonacci Search (Mencari Berdasarkan ID)|" << endl;
    cout << "|5. Bubble Sort (Mengurutkan Nama A-Z)       |" << endl;
    cout << "|6. Selection Sort (Mengurutkan Status)      |" << endl;
    cout << "|7. Update Status Hewan                      |" << endl;
    cout << "|8. Hapus Hewan Teradopsi                    |" << endl;
    cout << "|9. Keluar                                   |" << endl;
    cout << "==============================================" << endl;
    cout << "Pilih Menu 1-9: ";
}
void isiDataAwal(Hewan*& data, int& jumlah) {
    data = new Hewan[5];
    jumlah = 0;

    (data + jumlah)->id = 1;
    (data + jumlah)->nama = "Kiko";
    (data + jumlah)->jenis = "Kucing";
    (data + jumlah)->status = "Tersedia";
    (data + jumlah)->calonPemilik = "-";
    jumlah++;

    (data + jumlah)->id = 2;
    (data + jumlah)->nama = "Bruno";
    (data + jumlah)->jenis = "Anjing";
    (data + jumlah)->status = "Teradopsi";
    (data + jumlah)->calonPemilik = "Siti";
    jumlah++;

    (data + jumlah)->id = 3;
    (data + jumlah)->nama = "Mochi";
    (data + jumlah)->jenis = "Kelinci";
    (data + jumlah)->status = "Tersedia";
    (data + jumlah)->calonPemilik = "-";
    jumlah++;

    (data + jumlah)->id = 4;
    (data + jumlah)->nama = "Luna";
    (data + jumlah)->jenis = "Kucing";
    (data + jumlah)->status = "Tersedia";
    (data + jumlah)->calonPemilik = "-";
    jumlah++;

    (data + jumlah)->id = 5;
    (data + jumlah)->nama = "Rocky";
    (data + jumlah)->jenis = "Anjing";
    (data + jumlah)->status = "Teradopsi";
    (data + jumlah)->calonPemilik = "Rina";
    jumlah++;
}

int main() {
    Hewan* listHewan = nullptr;
    int totalData = 0;
    int pilihan;
    bool selesai = false;
    isiDataAwal(listHewan, totalData);

    while (selesai == false) {
        bersihkanLayar();
        tampilanMenu();
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            menampilkanDataHewan(listHewan, totalData);
        } else if (pilihan == 2) {
            menambahkanHewanBaru(listHewan, totalData);
        } else if (pilihan == 3) {
            string nama;
            cout << "Cari Nama Hewan: "; cin >> nama;
            int hasil = linearSearchHewan(listHewan, totalData, nama);
            if (hasil != -1) {
                cout << "\nData ada pada index ke-" << hasil << endl;
                cout << "ID: " << (listHewan + hasil)->id << endl;
                cout << "Nama: " << (listHewan + hasil)->nama << endl;
                cout << "Status: " << (listHewan + hasil)->status << endl;
                cout << "Calon Pemilik: " << (listHewan + hasil)->calonPemilik << endl;
            } else {
                cout << "\nHewan dengan nama tersebut TIDAK DITEMUKAN." << endl;
            }
            tungguEnter();
        } else if (pilihan == 4) {
            mengurutkanID(listHewan, totalData);
            
            int id;
            cout << "Cari ID Hewan: "; cin >> id;
            int hasil = fibonacciSearchHewan(listHewan, totalData, id);
            if (hasil != -1) {
                cout << "\nData ada pada index ke-" << hasil << endl;
                cout << "ID: " << (listHewan + hasil)->id << endl;
                cout << "Nama: " << (listHewan + hasil)->nama << endl;
                cout << "Status: " << (listHewan + hasil)->status << endl;
                cout << "Calon Pemilik: " << (listHewan + hasil)->calonPemilik << endl;
            } else {
                cout << "\nHewan dengan ID tersebut TIDAK DITEMUKAN." << endl;
            }
            tungguEnter();
        } else if (pilihan == 5) {
            mengurutkanNamaHewan(listHewan, totalData);
            menampilkanDataHewan(listHewan, totalData);
        } else if (pilihan == 6) {
            mengurutkanStatus(listHewan, totalData);
            menampilkanDataHewan(listHewan, totalData);
        } else if (pilihan == 7) {
            updateStatus(listHewan, totalData);
        } else if (pilihan == 8) {
            hapusHewan(listHewan, totalData);
        } else if (pilihan == 9) {
            cout << "\nTerima kasih telah menggunakan Program Adopsi Hewan!" << endl;
            selesai = true;
        } else {
            cout << "\nPilihan tidak valid." << endl;
            tungguEnter();
        }
    }

    delete[] listHewan;
    return 0;
}