#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int *pointerAwal = arr;           
    int *pointerAkhir = arr + n - 1; 
    int nilaiSementara;
    
    while (pointerAwal < pointerAkhir) {
        nilaiSementara = *pointerAwal;          
        *pointerAwal = *pointerAkhir;
        *pointerAkhir = nilaiSementara;
        
        pointerAwal++;   
        pointerAkhir--;
    }
}
void tampilkanArray(int* arr, int n) {
    for(int* pointer = arr; pointer < arr + n; pointer++) {
        cout << "array[" << (pointer - arr) << "] bernilai " 
             << *pointer << " (Alamat Memori: " << pointer << ")" << endl;
    }
}
int main() {
    int arrayBilanganPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    cout << "=== SEBELUM DIBALIK ===" << endl;
    tampilkanArray(arrayBilanganPrima, n);
    reverseArray(arrayBilanganPrima, n);
    cout << "\n=== SETELAH DIBALIK ===" << endl;
    tampilkanArray(arrayBilanganPrima, n);
    
    return 0;
}