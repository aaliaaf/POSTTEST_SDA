#include <iostream>
#include <string>
#include <cstdlib>
#include "../table/text_table.h"
using namespace std;
const int MAX = 100;

struct Hewan {
    int id;
    string nama;
    string jenis;
    string status;
    string calonPemilik;
};
struct Antrian {
    Hewan data[MAX];
    int front;
    int rear;
};
struct Riwayat {
    Hewan data[MAX];
    int top;
};
void tukarData(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tungguEnter() {
    cout << "\nTekan enter untuk lanjut...";
    cin.ignore(1000, '\n');
    cin.get();
}

void bersihkanLayar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void tampilanMenu() {
    cout << "==============================================" << endl;
    cout << "|         MENU PROGRAM ADOPSI HEWAN          |" << endl;
    cout << "==============================================" << endl;
    cout << "|1. Tampilkan Semua Data Hewan               |" << endl;
    cout << "|2. Tambah Data Hewan Baru                   |" << endl;
    cout << "|3. Linear Search (Mencari Berdasarkan Nama) |" << endl;
    cout << "|4. Fibonacci Search (Mencari Berdasarkan ID)|" << endl;
    cout << "|5. Bubble Sort (Mengurutkan Nama A-Z)       |" << endl;
    cout << "|6. Selection Sort (Mengurutkan Status)      |" << endl;
    cout << "|7. Update Status Hewan                      |" << endl;
    cout << "|8. Hapus Hewan Teradopsi                    |" << endl;
    cout << "|9. Antrian & Riwayat Medis                  |" << endl;
    cout << "|10. Keluar                                  |" << endl;
    cout << "==============================================" << endl;
    cout << "Pilih Menu 1-10: ";
}

void tampilanmenuMedisHewan() {
    cout << "\n==============================================" << endl;
    cout << "|      MENU ANTRIAN & RIWAYAT MEDIS          |" << endl;
    cout << "==============================================" << endl;
    cout << "|1. Enqueue (Daftar Antrian Pemeriksaan)     |" << endl;
    cout << "|2. Dequeue (Panggil Pasien Terdepan)        |" << endl;
    cout << "|3. Push (Catat Tindakan ke Riwayat)         |" << endl;
    cout << "|4. Pop (Batalkan Tindakan Terakhir)         |" << endl;
    cout << "|5. Peek (Lihat Data Tanpa Menghapus)        |" << endl;
    cout << "|6. Tampilkan Semua Antrian                  |" << endl;
    cout << "|7. Tampilkan Semua Riwayat                  |" << endl;
    cout << "|8. Kembali ke Menu Utama                    |" << endl;
    cout << "==============================================" << endl;
    cout << "Pilih Menu 1-8: ";
}

void declareAntrian(Antrian* q) {
    q->front = -1;
    q->rear = -1;
}
void declareRiwayat(Riwayat* s) {
    s->top = -1;
}
bool antrianPenuh(Antrian* q) {
    return (q->rear == MAX - 1);
}
bool antrianKosong(Antrian* q) {
    return (q->front == -1 || q->front > q->rear);
}
bool riwayatPenuh(Riwayat* s) {
    return (s->top == MAX - 1);
}
bool riwayatKosong(Riwayat* s) {
    return (s->top == -1);
}

void enqueue(Antrian* q, Hewan hewan) {
    if (antrianPenuh(q)) {
        cout << "\nAntrian penuh! Tidak dapat menambah pasien." << endl;
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    *(q->data + q->rear) = hewan;
    cout <<  hewan.nama << " berhasil masuk antrian!" << endl;
}

Hewan dequeue(Antrian* q) {
    Hewan kosong;
    kosong.id = -1;
    if (antrianKosong(q)) {
        cout << "\nAntrian kosong! Tidak ada pasien untuk dipanggil." << endl;
        return kosong;
    }
    Hewan pasien = *(q->data + q->front);
    cout << "\nMemanggil pasien: " << pasien.nama << " (ID: " << pasien.id << ")" << endl;
    q->front++;
    if (q->front > q->rear) {
        declareAntrian(q);
    }
    return pasien;
}

void push(Riwayat* s, Hewan hewan) {
    if (riwayatPenuh(s)) {
        cout << "\nRiwayat penuh! Tidak dapat mencatat tindakan lagi." << endl;
        return;
    }
    s->top++;
    *(s->data + s->top) = hewan;
    cout << "\nTindakan untuk " << hewan.nama << " tercatat di riwayat!" << endl;
}

Hewan pop(Riwayat* s) {
    Hewan kosong;
    kosong.id = -1;
    if (riwayatKosong(s)) {
        cout << "\nRiwayat kosong! Tidak ada tindakan untuk dibatalkan." << endl;
        return kosong;
    }
    Hewan terakhir = *(s->data + s->top);
    cout << "\nMembatalkan tindakan terakhir: " << terakhir.nama << " (ID: " << terakhir.id << ")" << endl;
    s->top--;
    return terakhir;
}

Hewan peekAntrian(Antrian* q) {
    Hewan kosong;
    kosong.id = -1;
    if (antrianKosong(q)) {
        cout << "\nAntrian kosong!" << endl;
        return kosong;
    }
    return *(q->data + q->front);
}

Hewan peekRiwayat(Riwayat* s) {
    Hewan kosong;
    kosong.id = -1;
    if (riwayatKosong(s)) {
        cout << "\nRiwayat kosong!" << endl;
        return kosong;
    }
    return *(s->data + s->top);
}

void tampilAntrian(Antrian* q) {
    cout << "\nANTRIAN PEMERIKSAAN HEWAN" << endl;
    if (antrianKosong(q)) {
        cout << "(Antrian kosong)" << endl;
    } else {
        TextTable tabel('-', '|', '+');
        tabel.add("No");
        tabel.add("ID");
        tabel.add("Nama");
        tabel.add("Jenis");
        tabel.add("Status");
        tabel.endOfRow();
        for (int i = q->front; i <= q->rear; i++) {
            tabel.add(to_string(i - q->front + 1));
            tabel.add(to_string((q->data + i)->id));
            tabel.add((q->data + i)->nama);
            tabel.add((q->data + i)->jenis);
            tabel.add((q->data + i)->status);
            tabel.endOfRow();
        }
        cout << tabel;
    }
}

void tampilRiwayat(Riwayat* s) {
    cout << "\nRIWAYAT TINDAKAN MEDIS" << endl;
    if (riwayatKosong(s)) {
        cout << "(Belum ada riwayat tindakan)" << endl;
    } else {
        TextTable tabel('-', '|', '+');
        tabel.add("No");
        tabel.add("ID");
        tabel.add("Nama");
        tabel.add("Jenis");
        tabel.add("Tindakan");
        tabel.endOfRow();
        for (int i = 0; i <= s->top; i++) {
            tabel.add(to_string(i + 1));
            tabel.add(to_string((s->data + i)->id));
            tabel.add((s->data + i)->nama);
            tabel.add((s->data + i)->jenis);
            tabel.add("Pemeriksaan");
            tabel.endOfRow();
        }
        cout << tabel;
    }
}

void menuMedisHewan(Antrian* antrian, Riwayat* riwayat, Hewan* dataHewan, int totalData) {
    int pilihan;
    bool kembali = false;
    
    while (!kembali) {
        bersihkanLayar();
        tampilanmenuMedisHewan();
        cin >> pilihan;
        cin.ignore(1000, '\n');
        
        if (pilihan == 1) {
            int id;
            cout << "\nMasukkan ID hewan untuk antrian: ";
            cin >> id;
            cin.ignore(1000, '\n');
            int idx = -1;
            for (int i = 0; i < totalData; i++) {
                if ((dataHewan + i)->id == id) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                cout << "\nHewan dengan ID tersebut tidak ditemukan!" << endl;
            } else {
                enqueue(antrian, *(dataHewan + idx));
            }
            tungguEnter();
        }
        else if (pilihan == 2) {
            Hewan pasien = dequeue(antrian);
            if (pasien.id != -1) {
                cout << "\nPasien siap diperiksa dokter." << endl;
                push(riwayat, pasien);
            }
            tungguEnter();
        }
        else if (pilihan == 3) {
            int id;
            cout << "\nMasukkan ID hewan untuk dicatat riwayat: ";
            cin >> id;
            cin.ignore(1000, '\n');
            int idx = -1;
            for (int i = 0; i < totalData; i++) {
                if ((dataHewan + i)->id == id) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                cout << "\nHewan dengan ID tersebut tidak ditemukan!" << endl;
            } else {
                push(riwayat, *(dataHewan + idx));
            }
            tungguEnter();
        }
        else if (pilihan == 4) {
            pop(riwayat);
            tungguEnter();
        }
        else if (pilihan == 5) {
            cout << "\n--- PEEK ANTRIAN ---";
            Hewan depan = peekAntrian(antrian);
            if (depan.id != -1) {
                cout << "Pasien terdepan: " << depan.nama << " (ID: " << depan.id << ")" << endl;
            }
            cout << "\n--- PEEK RIWAYAT ---";
            Hewan terakhir = peekRiwayat(riwayat);
            if (terakhir.id != -1) {
                cout << "Tindakan terakhir: " << terakhir.nama << " (ID: " << terakhir.id << ")" << endl;
            }
            tungguEnter();
        }
        else if (pilihan == 6) {
            tampilAntrian(antrian);
            tungguEnter();
        }
        else if (pilihan == 7) {
            tampilRiwayat(riwayat);
            tungguEnter();
        }
        else if (pilihan == 8) {
            kembali = true;
        }
        else {
            cout << "\nPilihan tidak valid!" << endl;
            tungguEnter();
        }
    }
}

void menampilkanDataHewan(Hewan* data, int jumlah) {
    cout << "\nDAFTAR HEWAN YANG TERSEDIA" << endl;
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

    cout << "ID Hewan         : "; 
    cin >> dataBaru[jumlah].id;
    cin.ignore(1000, '\n');

    cout << "Nama Hewan       : "; 
    getline(cin, dataBaru[jumlah].nama);

    cout << "Jenis Hewan      : "; 
    getline(cin, dataBaru[jumlah].jenis);

    cout << "Status (Tersedia/Teradopsi): "; 
    getline(cin, dataBaru[jumlah].status);

    cout << "Calon Pemilik    : "; 
    getline(cin, dataBaru[jumlah].calonPemilik);

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
    cout << "Masukkan ID Hewan: "; 
    cin >> id;
    cin.ignore(1000, '\n');
    
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
    
    cout << "\nUpdate Status Baru (Tersedia/Teradopsi): "; 
    getline(cin, data[idx].status);

    cout << "Update Calon Pemilik: "; 
    getline(cin, data[idx].calonPemilik);
    
    cout << "\nStatus hewan berhasil diupdate!" << endl;
    tungguEnter();
}

void hapusHewan(Hewan*& data, int& jumlah) {
    cout << "==================================" << endl;
    cout << "|      HAPUS HEWAN TERADOPSI     |" << endl;
    cout << "==================================" << endl;

    int id;
    cout << "Masukkan ID hewan yang akan dihapus: "; 
    cin >> id;
    cin.ignore(1000, '\n');
    
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
    cout << "\nYakin ingin menghapus? (y/n): "; 
    cin >> konfirmasi;
    cin.ignore(1000, '\n');
    
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
    
    Antrian antrianPemeriksaan;
    Riwayat riwayatTindakan;
    
    declareAntrian(&antrianPemeriksaan);
    declareRiwayat(&riwayatTindakan);
    
    isiDataAwal(listHewan, totalData);

    while (!selesai) {
        bersihkanLayar();
        tampilanMenu();
        cin >> pilihan;
        cin.ignore(1000, '\n');
        cout << endl;

        if (pilihan == 1) {
            menampilkanDataHewan(listHewan, totalData);
        } else if (pilihan == 2) {
            menambahkanHewanBaru(listHewan, totalData);
        } else if (pilihan == 3) {
            string nama;
            cout << "Cari Nama Hewan: "; 
            getline(cin, nama);
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
            cout << "Cari ID Hewan: "; 
            cin >> id;
            cin.ignore(1000, '\n');
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
            menuMedisHewan(&antrianPemeriksaan, &riwayatTindakan, listHewan, totalData);
        } else if (pilihan == 10) {
            cout << "\nTerima kasih telah menggunakan Pawcare Petshop!" << endl;
            selesai = true;
        } else {
            cout << "\nPilihan tidak valid." << endl;
            tungguEnter();
        }
    }

    delete[] listHewan;
    return 0;
}