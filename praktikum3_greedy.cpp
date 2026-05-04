#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void coinExchange(int koin[], int n, int target) {
    vector<int> hasil;
    int totalSekarang = 0;

    // Strategi Greedy: Urutkan koin dari terbesar ke terkecil
    sort(koin, koin + n, greater<int>());

    cout << "=== PROSES ALGORITMA GREEDY ===" << endl;
    
    for (int i = 0; i < n; i++) {
        while (totalSekarang + koin[i] <= target) {
            totalSekarang += koin[i];
            hasil.push_back(koin[i]);
            cout << "Pilih koin: " << koin[i] << " | Total: " << totalSekarang << endl;
        }
    }

    if (totalSekarang == target) {
        cout << "\nHASIL AKHIR:" << endl;
        cout << "Jumlah koin minimum: " << hasil.size() << endl;
        cout << "Koin yang digunakan: { ";
        for (int k : hasil) {
            cout << k << " ";
        }
        cout << "}" << endl;
    } else {
        cout << "\nTidak ada solusi yang tepat untuk nilai tersebut." << endl; //
    }
}

int main() {
    int koin[] = {5000, 2000, 1000, 500};
    int n = sizeof(koin) / sizeof(koin[0]);
    int uangDitukar;

    cout << "Masukkan nominal uang yang ingin ditukar: ";
    cin >> uangDitukar;

    coinExchange(koin, n, uangDitukar);

    return 0;
}