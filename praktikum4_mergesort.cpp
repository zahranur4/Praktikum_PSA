#include <iostream>
using namespace std;

void merge(int A[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = A[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = A[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { A[k] = L[i]; i++; }
        else { A[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { A[k] = L[i]; i++; k++; }
    while (j < n2) { A[k] = R[j]; j++; k++; }
}

void mergeSort(int A[], int i, int j) {
    if (i < j) {
        int k = (i + j) / 2;    
        mergeSort(A, i, k);      
        mergeSort(A, k + 1, j);  
        merge(A, i, k, j);       
    }
}

int main() {
    int data[] = {4, 12, 23, 9, 21, 1, 35, 2, 24}; 
    int n = sizeof(data) / sizeof(data[0]);

    cout << "=== TUGAS MERGE SORT (DIVIDE & CONQUER) ===\n";
    mergeSort(data, 0, n - 1);
    cout << "Hasil Terurut: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}