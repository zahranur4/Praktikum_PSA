#include <iostream>
#include <string>

using namespace std;

// 1. Kasus 1: Mencari Bilangan Terbesar (Hal. 16)
void cariBilanganTerbesar(int a[], int n) {
    int maks = a[0]; // Anggap bilangan pertama adalah yang terbesar
    for (int i = 1; i < n; i++) {
        if (a[i] > maks) {
            maks = a[i]; // Update nilai maks jika ditemukan yang lebih besar
        }
    }
    cout << "1. BILANGAN TERBESAR\n";
    cout << "Bilangan terbesar dalam array adalah: " << maks << "\n\n";
}

// 2. Kasus 2: Sequential Search (Hal. 19)
void sequentialSearch(int arr[], int n, int data_cari) {
    bool ketemu = false;
    int i = 0;
    
    // Melakukan pengecekan satu-persatu (Straightforward)
    while (!ketemu && i < n) {
        if (arr[i] == data_cari) {
            ketemu = true;
        } else {
            i++;
        }
    }

    cout << "2. SEQUENTIAL SEARCH\n";
    if (ketemu) {
        cout << "Data " << data_cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << "Data " << data_cari << " tidak ditemukan" << endl;
    }
    cout << endl;
}

// 3. Kasus 3: Bubble Sort Ascending (Hal. 22)
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            // Membandingkan elemen yang berdekatan
            if (arr[j] < arr[j - 1]) {
                // Tukar data (Swap)
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main() {
    // Inisialisasi data sesuai contoh materi (Hal. 18 & 21)
    int data[] = {5, 3, 7, 9, 2, 3, 6, 4, 3, 1};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "=== PRAKTIKUM PSA 2: STRATEGI BRUTE FORCE ===\n\n";

    // Menjalankan Kasus 1
    cariBilanganTerbesar(data, n);

    // Menjalankan Kasus 2
    sequentialSearch(data, n, 9); // Mencari angka 9 sesuai materi hal. 18

    // Menjalankan Kasus 3
    cout << "3. BUBBLE SORT (PENGURUTAN)\n";
    cout << "Data sebelum diurutkan: ";
    for(int k = 0; k < n; k++) cout << data[k] << " ";
    
    bubbleSort(data, n);
    
    cout << "\nData setelah diurutkan: ";
    for(int k = 0; k < n; k++) cout << data[k] << " ";
    cout << "\n\n--------------------------------------------\n";

    return 0;
}