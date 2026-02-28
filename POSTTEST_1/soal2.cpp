#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};
int ipkTertinggi(Mahasiswa data[], int jumlah) {
    int indeksIpkTertinggi = 0;
    
    for(int i = 1; i < jumlah; i++) {
        if(data[i].ipk > data[indeksIpkTertinggi].ipk) {
            indeksIpkTertinggi = i;
        }
    }
    return indeksIpkTertinggi;
}
int main() {
    Mahasiswa mhs[5];
    cout << "=== DATA MAHASISWA ===" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        
        cout << "Nama : "; 
        cin >> mhs[i].nama; 
        
        cout << "NIM  : "; 
        cin >> mhs[i].nim;  
        
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }
    int indeks = ipkTertinggi(mhs, 5);
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[indeks].nama << endl;
    cout << "NIM  : " << mhs[indeks].nim << endl;
    cout << "IPK  : " << mhs[indeks].ipk << endl;
    cout << "-------------------------------" << endl;
    
    return 0;
}