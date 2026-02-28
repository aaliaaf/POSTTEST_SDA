#include <iostream>
using namespace std;

int FindMin(int A[], int n) {
    int nilaiMinimum = A[0];
    
    for(int penunjuk = 1; penunjuk < n; penunjuk++) {
        if(A[penunjuk] < nilaiMinimum) {
            nilaiMinimum = A[penunjuk];
        }
    }
    return nilaiMinimum;
}
int main() {
    int arrayFibonacci[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int elemen = 8;
    
    int hasilMinimum = FindMin(arrayFibonacci, elemen);
    
    int indeksnya = -1;
    for(int cari = 0; cari < elemen; cari++) {
        if(arrayFibonacci[cari] == hasilMinimum) {
            indeksnya = cari;
            break;
        }
    }
    cout << "Nilai Minimum: " << hasilMinimum << endl;
    cout << "Indeks: " << indeksnya << endl;
    
    return 0;
}