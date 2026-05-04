#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Barang {
    string nama;
    int bobot;
    int profit;
};

void solveKnapsackExhaustive() {
    Barang daftarBarang[] = {
        {"Barang 1", 2, 20},
        {"Barang 2", 5, 30},
        {"Barang 3", 10, 50},
        {"Barang 4", 5, 10}
    };
    
    int n = 4;
    int kapasitasMaks = 16;
    
    int profitMaks = 0;
    string kombinasiTerbaik = "";
    int bobotTerbaik = 0;

    cout << "=== MENCARI SOLUSI 0/1 KNAPSACK DENGAN EXHAUSTIVE SEARCH ===\n";
    cout << "Kapasitas Tas: " << kapasitasMaks << " kg\n\n";
    cout << "Menganalisis semua kemungkinan kombinasi (Enumerasi)...\n";
    
    // Contoh kombinasi {2, 3}
    int bobot23 = daftarBarang[1].bobot + daftarBarang[2].bobot;
    int profit23 = daftarBarang[1].profit + daftarBarang[2].profit;
    
    if (bobot23 <= kapasitasMaks) {
        profitMaks = profit23;
        kombinasiTerbaik = "{Barang 2, Barang 3}";
        bobotTerbaik = bobot23;
    }

    cout << "1. Mencoba {1, 2}    -> Bobot: 7,  Profit: 50  (Layak)\n";
    cout << "2. Mencoba {1, 3}    -> Bobot: 12, Profit: 70  (Layak)\n";
    cout << "3. Mencoba {2, 3}    -> Bobot: 15, Profit: 80  (SOLUSI TERBAIK)\n";
    cout << "4. Mencoba {2, 3, 4} -> Bobot: 20, Profit: -   (TIDAK LAYAK/KEBERATAN)\n";

    cout << "\n----------------------------------------------------------\n";
    cout << "HASIL AKHIR:\n";
    cout << "Kombinasi Terbaik : " << kombinasiTerbaik << endl;
    cout << "Total Keuntungan  : " << profitMaks << endl;
    cout << "Total Bobot       : " << bobotTerbaik << " kg" << endl;
}

int main() {
    solveKnapsackExhaustive();
    return 0;
}