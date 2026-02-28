#include <iostream>  
using namespace std;

void tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int angkaPertama;
    int angkaKedua;

    cout << "Masukkan nilai pertama: ";
    cin >> angkaPertama; 
    cout << "Masukkan nilai kedua: ";
    cin >> angkaKedua;

    cout << "\n=== SEBELUM PERTUKARAN ===" << endl;
    cout << "Nilai Angka Pertama: " << angkaPertama << endl;
    cout << "Nilai Angka Kedua: " << angkaKedua << endl;

    tukar(&angkaPertama, &angkaKedua);

    cout << "\n=== SESUDAH PERTUKARAN ===" << endl;
    cout << "Nilai Angka Pertama: " << angkaPertama << endl;
    cout << "Nilai Angka Kedua: " << angkaKedua << endl;

    return 0;
}