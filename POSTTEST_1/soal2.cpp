#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

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
    int indeksIpkTertinggi = 0;
    for(int i = 1; i < 5; i++) {
        if(mhs[i].ipk > mhs[indeksIpkTertinggi].ipk) {
            indeksIpkTertinggi = i;
        }
    }
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[indeksIpkTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksIpkTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksIpkTertinggi].ipk << endl;
    cout << "-------------------------------" << endl;
    
    return 0;
}