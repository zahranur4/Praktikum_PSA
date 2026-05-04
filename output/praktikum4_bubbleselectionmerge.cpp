#include <iostream>
#include <cstdlib>

using namespace std;

typedef int larik[10];

void baca_data(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> A[i];
    }
}

void cetak_data(int A[], int n) {
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

void tukar_data(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minimum(int A[], int dari, int n, int *tempat) {
    int i, min_val = A[dari];
    *tempat = dari;
    for (i = dari + 1; i < n; i++) {
        if (A[i] < min_val) {
            min_val = A[i];
            *tempat = i;
        }
    }
}

void bubble_sort(int x[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j]) tukar_data(&x[i], &x[j]);
        }
    }
}

void selection_sort(int A[], int n) {
    int i, t;
    for (i = 0; i < n; i++) {
        minimum(A, i, n, &t);
        tukar_data(&A[i], &A[t]);
    }
}

void merge(larik a, int kiri, int tengah, int kanan) {
    int bagkir, postemp, bykel, i;
    larik temp;
    bagkir = tengah - 1;
    postemp = kiri;
    bykel = kanan - kiri + 1;

    while ((kiri <= bagkir) && (tengah <= kanan)) {
        if (a[kiri] <= a[tengah]) {
            temp[postemp] = a[kiri];
            kiri++;
        } else {
            temp[postemp] = a[tengah];
            tengah++;
        }
        postemp++;
    }

    while (kiri <= bagkir) { temp[postemp] = a[kiri]; postemp++; kiri++; }
    while (tengah <= kanan) { temp[postemp] = a[tengah]; postemp++; tengah++; }

    for (i = 1; i <= bykel; i++) {
        a[kanan] = temp[kanan];
        kanan--;
    }
}

void merge_sort(larik A, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        merge_sort(A, kiri, tengah);
        merge_sort(A, tengah + 1, kanan);
        merge(A, kiri, tengah + 1, kanan);
    }
}

int main() {
    int data[10], n, pilih;
    t1:
    cout << "\n1. Bubble Sort\n2. Selection Sort\n3. Merge Sort\nPilihan: ";
    cin >> pilih;
    if (pilih < 1 || pilih > 3) { cout << "Ulangi!\n"; goto t1; }

    cout << "Masukan jumlah data (max 10): "; cin >> n;
    baca_data(data, n);

    switch (pilih) {
        case 1: bubble_sort(data, n); break;
        case 2: selection_sort(data, n); break;
        case 3: merge_sort(data, 0, n - 1); break;
    }
    cout << "Hasil pengurutan: "; cetak_data(data, n);
    return 0;
}