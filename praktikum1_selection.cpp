#include <iostream>
using namespace std;

// 1. Fungsi Selection Sort (Langkah Praktikum 1.5)
void selectionSort(int a[], int n) {
    int i, j, imaks, temp;
 
    for (i = n - 1; i >= 1; i--) { 
        imaks = 0; 
        for (j = 1; j <= i; j++) {
            if (a[j] > a[imaks]) {
                imaks = j;
            }
        }

        temp = a[i];
        a[i] = a[imaks];
        a[imaks] = temp;
    }
}

// 2. Fungsi Insertion Sort (Tugas Post-Test 1.6)
void insertionSort(int a[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = a[j]; 
        i = j - 1;

        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

int main() {
    int data1[] = {23, 10, 15, 8, 12}; 
    int data2[] = {23, 10, 15, 8, 12};
    int n = 5;

    cout << "LAPORAN PRAKTIKUM 1: KOMPLEKSITAS ALGORITMA\n\n";

    // Menjalankan Selection Sort
    selectionSort(data1, n);
    cout << "Hasil Selection Sort (Analisis 1.5): ";
    for(int counter = 0; counter < n; counter++) cout << data1[counter] << " ";

    cout << "\n---------------------------------------------------\n";

    // Menjalankan Insertion Sort
    insertionSort(data2, n);
    cout << "Hasil Insertion Sort (Tugas 1.6)    : ";
    for(int counter = 0; counter < n; counter++) cout << data2[counter] << " ";
    cout << endl;

    return 0;
}