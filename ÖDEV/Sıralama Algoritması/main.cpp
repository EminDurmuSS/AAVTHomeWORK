#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(int dizi[], int sol, int sag) {
    int i = sol, j = sag, tmp;
    int pivot = dizi[(sol + sag) / 2];

    while (i <= j) {
        while (dizi[i] < pivot) {
            i++;
        }
        while (dizi[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = tmp;
            i++;
            j--;
        }
    }
    if (sol < j) {
        quicksort(dizi, sol, j);
    }
    if (i < sag) {
        quicksort(dizi, i, sag);
    }
}

int main() {
    const int boyut = 10000;
    int dizi[boyut];

    // Diziye rastgele sayılar atama
    srand(time(NULL));
    for (int i = 0; i < boyut; i++) {
        dizi[i] = rand();
    }

    // Quicksort ile sıralama ve süre ölçümü
    clock_t baslangic = clock();
    quicksort(dizi, 0, boyut - 1);
    clock_t bitis = clock();
    double sure = (double)(bitis - baslangic) / CLOCKS_PER_SEC;
    cout << "Quicksort ile sıralama süresi: " << sure << " saniye" << endl;

    // BruteForce ile sıralama ve süre ölçümü
    baslangic = clock();
    for (int i = 0; i < boyut; i++) {
        for (int j = i + 1; j < boyut; j++) {
            if (dizi[j] < dizi[i]) {
                int tmp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = tmp;
            }
        }
    }
    bitis = clock();
    sure = (double)(bitis - baslangic) / CLOCKS_PER_SEC;
    cout << "BruteForce ile sıralama süresi: " << sure << " saniye" << endl;

    return 0;
}