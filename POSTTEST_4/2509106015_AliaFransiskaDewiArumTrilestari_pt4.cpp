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
    Hewan* next; 
};
struct Antrian {
    Hewan* front;
    Hewan* rear;
};
struct Riwayat {
    Hewan* top;
};
void tukarData(Hewan& a, Hewan& b) {
    Hewan* pA = &a; 
    Hewan* pB = &b;
    Hewan temp = *pA;
    *pA = *pB;
    *pB = temp;
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
    q->front = nullptr;
    q->rear = nullptr;
}

void declareRiwayat(Riwayat* s) {
    s->top = nullptr;
}

bool antrianKosong(Antrian* q) {
    return q->front == nullptr; 
}

bool riwayatKosong(Riwayat* s) {
    return s->top == nullptr;
}

void enqueue(Antrian* q, Hewan hewan) {
    Hewan* nodeBaru = new Hewan;
    *nodeBaru = hewan;
    nodeBaru->next = nullptr; 

    if (antrianKosong(q)) {
        q->front = q->rear = nodeBaru;
    } else {
        q->rear->next = nodeBaru;
        q->rear = nodeBaru;
    }
    cout << hewan.nama << " berhasil masuk antrian!" << endl;
}

Hewan dequeue(Antrian* q) {
    Hewan kosong; 
    kosong.id = -1; 
    kosong.next = nullptr;
    
    if (antrianKosong(q)) {
        cout << "\nAntrian kosong! Tidak ada pasien untuk dipanggil." << endl;
        return kosong;
    }
    
    Hewan* temp = q->front;
    Hewan dataPasien = *temp;
    dataPasien.next = nullptr;
    
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr; 
    }
    delete temp; 
    
    cout << "\nMemanggil pasien: " << dataPasien.nama << " (ID: " << dataPasien.id << ")" << endl;
    return dataPasien;
}

void push(Riwayat* s, Hewan hewan) {
    Hewan* nodeBaru = new Hewan;
    *nodeBaru = hewan;
    nodeBaru->next = s->top;
    s->top = nodeBaru;
    cout << "\nTindakan untuk " << hewan.nama << " tercatat di riwayat!" << endl;
}

Hewan pop(Riwayat* s) {
    Hewan kosong; 
    kosong.id = -1; 
    kosong.next = nullptr;
    
    if (riwayatKosong(s)) {
        cout << "\nRiwayat kosong! Tidak ada tindakan untuk dibatalkan." << endl;
        return kosong;
    }
    
    Hewan* temp = s->top;
    Hewan dataTerakhir = *temp;
    dataTerakhir.next = nullptr;
    
    s->top = s->top->next;
    delete temp; 
    
    cout << "\nMembatalkan tindakan terakhir: " << dataTerakhir.nama << " (ID: " << dataTerakhir.id << ")" << endl;
    return dataTerakhir;
}

Hewan peekAntrian(Antrian* q) {
    Hewan kosong; 
    kosong.id = -1; 
    kosong.next = nullptr;
    
    if (antrianKosong(q)) {
        cout << "\nAntrian kosong!" << endl;
        return kosong;
    }
    
    Hewan data = *(q->front);
    data.next = nullptr;
    return data;
}

Hewan peekRiwayat(Riwayat* s) {
    Hewan kosong; 
    kosong.id = -1; 
    kosong.next = nullptr;
    
    if (riwayatKosong(s)) {
        cout << "\nRiwayat kosong!" << endl;
        return kosong;
    }
    
    Hewan data = *(s->top);
    data.next = nullptr;
    return data;
}

void tampilAntrian(Antrian* q) {
    cout << "\nANTRIAN PEMERIKSAAN HEWAN" << endl;
    if (antrianKosong(q)) {
        cout << "(Antrian kosong)" << endl;
        tungguEnter(); 
        return;
    }
    
    TextTable tabel('-', '|', '+');
    tabel.add("No"); tabel.add("ID"); tabel.add("Nama"); tabel.add("Jenis"); tabel.add("Status");
    tabel.endOfRow();
    
    int no = 1;
    Hewan* curr = q->front;
    while (curr != nullptr) {
        tabel.add(to_string(no++));
        tabel.add(to_string(curr->id));
        tabel.add(curr->nama);
        tabel.add(curr->jenis);
        tabel.add(curr->status);
        tabel.endOfRow();
        curr = curr->next;
    }
    cout << tabel;
}

void tampilRiwayat(Riwayat* s) {
    cout << "\nRIWAYAT TINDAKAN MEDIS" << endl;
    if (riwayatKosong(s)) {
        cout << "(Belum ada riwayat tindakan)" << endl;
        tungguEnter(); 
        return;
    }
    
    TextTable tabel('-', '|', '+');
    tabel.add("No"); tabel.add("ID"); tabel.add("Nama"); tabel.add("Jenis"); tabel.add("Tindakan");
    tabel.endOfRow();
    
    int no = 1;
    Hewan* curr = s->top;
    while (curr != nullptr) {
        tabel.add(to_string(no++));
        tabel.add(to_string(curr->id));
        tabel.add(curr->nama);
        tabel.add(curr->jenis);
        tabel.add("Pemeriksaan");
        tabel.endOfRow();
        curr = curr->next;
    }
    cout << tabel;
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
            int id; cout << "\nMasukkan ID hewan untuk antrian: "; cin >> id; cin.ignore(1000, '\n');
            int idx = -1;
            for (int i = 0; i < totalData; i++) if (dataHewan[i].id == id) { idx = i; break; }
            if (idx == -1) cout << "\nHewan dengan ID tersebut tidak ditemukan!\n";
            else enqueue(antrian, dataHewan[idx]);
            tungguEnter();
        }
        else if (pilihan == 2) {
            Hewan pasien = dequeue(antrian);
            if (pasien.id != -1) { cout << "\nPasien siap diperiksa dokter.\n"; push(riwayat, pasien); }
            tungguEnter();
        }
        else if (pilihan == 3) {
            int id; cout << "\nMasukkan ID hewan untuk dicatat riwayat: "; cin >> id; cin.ignore(1000, '\n');
            int idx = -1;
            for (int i = 0; i < totalData; i++) if (dataHewan[i].id == id) { idx = i; break; }
            if (idx == -1) cout << "\nHewan dengan ID tersebut tidak ditemukan!\n";
            else push(riwayat, dataHewan[idx]);
            tungguEnter();
        }
        else if (pilihan == 4) { pop(riwayat); tungguEnter(); }
        else if (pilihan == 5) {
            cout << "\n--- PEEK ANTRIAN ---\n";
            Hewan depan = peekAntrian(antrian);
            if (depan.id != -1) cout << "Pasien terdepan: " << depan.nama << " (ID: " << depan.id << ")\n";
            cout << "\n--- PEEK RIWAYAT ---\n";
            Hewan terakhir = peekRiwayat(riwayat);
            if (terakhir.id != -1) cout << "Tindakan terakhir: " << terakhir.nama << " (ID: " << terakhir.id << ")\n";
            tungguEnter();
        }
        else if (pilihan == 6) { tampilAntrian(antrian); }
        else if (pilihan == 7) { tampilRiwayat(riwayat); }
        else if (pilihan == 8) { kembali = true; }
        else { cout << "\nPilihan tidak valid!\n"; tungguEnter(); }
    }
}

void menampilkanDataHewan(Hewan* data, int jumlah) {
    cout << "\nDAFTAR HEWAN YANG TERSEDIA" << endl;
    TextTable tabel('-', '|', '+');
    string judul[5] = {"ID", "Nama", "Jenis", "Status", "Calon Pemilik"};
    for(int i = 0; i < 5; i++) tabel.add(judul[i]);
    tabel.endOfRow();
    
    for (int i = 0; i < jumlah; i++) {
        tabel.add(to_string(data[i].id));
        tabel.add(data[i].nama); tabel.add(data[i].jenis); tabel.add(data[i].status); tabel.add(data[i].calonPemilik);
        tabel.endOfRow();
    }
    cout << tabel;
    tungguEnter();
}

void menambahkanHewanBaru(Hewan*& data, int& jumlah) {
    cout << "==================================\n|    MENU TAMBAH HEWAN ADOPSI    |\n==================================\n";
    Hewan* dataBaru = new Hewan[jumlah + 1];
    for (int i = 0; i < jumlah; i++) dataBaru[i] = data[i];

    cout << "ID Hewan         : "; cin >> dataBaru[jumlah].id; cin.ignore(1000, '\n');
    cout << "Nama Hewan       : "; getline(cin, dataBaru[jumlah].nama);
    cout << "Jenis Hewan      : "; getline(cin, dataBaru[jumlah].jenis);
    cout << "Status (Tersedia/Teradopsi): "; getline(cin, dataBaru[jumlah].status);
    cout << "Calon Pemilik    : "; getline(cin, dataBaru[jumlah].calonPemilik);
    dataBaru[jumlah].next = nullptr;

    delete[] data;
    data = dataBaru;
    jumlah++;
    cout << "\nData hewan berhasil ditambahkan!\n";
    tungguEnter();
}

void updateStatus(Hewan* data, int jumlah) {
    cout << "==================================\n|   UPDATE STATUS HEWAN ADOPSI   |\n==================================\n";
    int id; cout << "Masukkan ID Hewan: "; cin >> id; cin.ignore(1000, '\n');
    int idx = -1;
    for (int i = 0; i < jumlah; i++) if (data[i].id == id) { idx = i; break; }
    if (idx == -1) { cout << "\nID hewan tersebut tidak ditemukan!\n"; tungguEnter(); return; }
    
    cout << "\nData Ditemukan:\nID: " << data[idx].id << ", Nama: " << data[idx].nama << endl;
    cout << "Status Saat Ini: " << data[idx].status << endl;
    cout << "Calon Pemilik Saat Ini: " << data[idx].calonPemilik << endl;
    cout << "\nUpdate Status Baru (Tersedia/Teradopsi): "; getline(cin, data[idx].status);
    cout << "Update Calon Pemilik: "; getline(cin, data[idx].calonPemilik);
    cout << "\nStatus hewan berhasil diupdate!\n";
    tungguEnter();
}

void hapusHewan(Hewan*& data, int& jumlah) {
    cout << "==================================\n|      HAPUS HEWAN TERADOPSI     |\n==================================\n";
    int id; cout << "Masukkan ID hewan yang akan dihapus: "; cin >> id; cin.ignore(1000, '\n');
    int idx = -1;
    for (int i = 0; i < jumlah; i++) if (data[i].id == id) { idx = i; break; }
    if (idx == -1) { cout << "\nID hewan tersebut tidak ditemukan!\n"; tungguEnter(); return; }
    
    cout << "\nData yang akan dihapus:\nID: " << data[idx].id << ", Nama: " << data[idx].nama << endl;
    char konfirmasi; cout << "\nYakin ingin menghapus? (y/n): "; cin >> konfirmasi; cin.ignore(1000, '\n');
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        Hewan* dataBaru = new Hewan[jumlah - 1];
        int j = 0;
        for (int i = 0; i < jumlah; i++) if (i != idx) dataBaru[j++] = data[i];
        delete[] data;
        data = dataBaru;
        jumlah--;
        cout << "\nHewan berhasil dihapus!\n";
    } else { cout << "\nPenghapusan dibatalkan.\n"; }
    tungguEnter();
}

int linearSearchHewan(Hewan* data, int jumlah, string namaCari) {
    for (int i = 0; i < jumlah; i++) if (data[i].nama == namaCari) return i;
    return -1;
}

int fibonacciSearchHewan(Hewan* data, int jumlah, int idCari) {
    int FIB2 = 0, FIB1 = 1, FIB = FIB2 + FIB1;
    while (FIB < jumlah) { FIB2 = FIB1; FIB1 = FIB; FIB = FIB2 + FIB1; }
    int offset = -1;
    while (FIB > 1) {
        int idx = (offset + FIB2 < jumlah - 1) ? offset + FIB2 : jumlah - 1;
        if (data[idx].id < idCari) { FIB = FIB1; FIB1 = FIB2; FIB2 = FIB - FIB1; offset = idx; }
        else if (data[idx].id > idCari) { FIB = FIB2; FIB1 = FIB1 - FIB2; FIB2 = FIB - FIB1; }
        else return idx;
    }
    if (FIB1 && (offset + 1 < jumlah) && data[offset + 1].id == idCari) return offset + 1;
    return -1;
}

void mengurutkanNamaHewan(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++)
        for (int j = 0; j < jumlah - i - 1; j++)
            if (data[j].nama > data[j+1].nama) tukarData(data[j], data[j+1]); // Parameter reference
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z)!\n";
}

void mengurutkanStatus(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int idxTarget = i;
        for (int j = i + 1; j < jumlah; j++)
            if (data[j].status < data[idxTarget].status) idxTarget = j;
        if (idxTarget != i) tukarData(data[i], data[idxTarget]); // Parameter reference
    }
    cout << "Data berhasil diurutkan berdasarkan Status!\n";
}

void mengurutkanID(Hewan* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++)
        for (int j = 0; j < jumlah - i - 1; j++)
            if (data[j].id > data[j+1].id) tukarData(data[j], data[j+1]); // Parameter reference
}

void isiDataAwal(Hewan*& data, int& jumlah) {
    data = new Hewan[5]; jumlah = 0;
    string n[5] = {"Kiko","Bruno","Mochi","Luna","Rocky"};
    string j[5] = {"Kucing","Anjing","Kelinci","Kucing","Anjing"};
    string s[5] = {"Tersedia","Teradopsi","Tersedia","Tersedia","Teradopsi"};
    string c[5] = {"-","Siti","-","-","Rina"};
    for(int i=0; i<5; i++){
        data[jumlah].id = i+1; data[jumlah].nama = n[i]; data[jumlah].jenis = j[i];
        data[jumlah].status = s[i]; data[jumlah].calonPemilik = c[i]; data[jumlah].next = nullptr;
        jumlah++;
    }
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

        if (pilihan == 1) menampilkanDataHewan(listHewan, totalData);
        else if (pilihan == 2) menambahkanHewanBaru(listHewan, totalData);
        else if (pilihan == 3) {
            string nama; cout << "Cari Nama Hewan: "; getline(cin, nama);
            int hasil = linearSearchHewan(listHewan, totalData, nama);
            if (hasil != -1) {
                cout << "\nData ada pada index ke-" << hasil << endl;
                cout << "ID: " << listHewan[hasil].id << "\nNama: " << listHewan[hasil].nama 
                     << "\nStatus: " << listHewan[hasil].status << "\nCalon Pemilik: " << listHewan[hasil].calonPemilik << endl;
            } else cout << "\nHewan dengan nama tersebut TIDAK DITEMUKAN.\n";
            tungguEnter();
        }
        else if (pilihan == 4) {
            int id; cout << "Cari ID Hewan: "; cin >> id; cin.ignore(1000, '\n');
            int hasil = fibonacciSearchHewan(listHewan, totalData, id);
            if (hasil != -1) {
                cout << "\nData ada pada index ke-" << hasil << endl;
                cout << "ID: " << listHewan[hasil].id << "\nNama: " << listHewan[hasil].nama 
                     << "\nStatus: " << listHewan[hasil].status << "\nCalon Pemilik: " << listHewan[hasil].calonPemilik << endl;
            } else cout << "\nHewan dengan ID tersebut TIDAK DITEMUKAN.\n";
            tungguEnter();
        }
        else if (pilihan == 5) { mengurutkanNamaHewan(listHewan, totalData); menampilkanDataHewan(listHewan, totalData); }
        else if (pilihan == 6) { mengurutkanStatus(listHewan, totalData); menampilkanDataHewan(listHewan, totalData); }
        else if (pilihan == 7) updateStatus(listHewan, totalData);
        else if (pilihan == 8) hapusHewan(listHewan, totalData);
        else if (pilihan == 9) menuMedisHewan(&antrianPemeriksaan, &riwayatTindakan, listHewan, totalData);
        else if (pilihan == 10) { cout << "\nTerima kasih telah menggunakan Pawcare Petshop!\n"; selesai = true; }
        else { cout << "\nPilihan tidak valid.\n"; tungguEnter(); }
    }

    delete[] listHewan;
    return 0;
}