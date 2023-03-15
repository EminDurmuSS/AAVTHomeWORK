#include <iostream>
#include <ctime>
using namespace std;

int findMaxLinear(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMaxBruteForce(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
        }
    }
    return max;
}

int main() {
    int n = 10000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    clock_t start = clock();
    int max_linear = findMaxLinear(arr, n);
    clock_t end = clock();
    double time_linear = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int max_brute_force = findMaxBruteForce(arr, n);
    end = clock();
    double time_brute_force = double(end - start) / CLOCKS_PER_SEC;

    cout << "En büyük sayý (Lineer Algoritma): " << max_linear << endl;
    cout << "Çalýþma süresi (Lineer Algoritma): " << time_linear << " saniye" << endl;

    cout << "En büyük sayý (Brute Force Algoritma): " << max_brute_force << endl;
    cout << "Çalýþma süresi (Brute Force Algoritma): " << time_brute_force << " saniye" << endl;

    return 0;
}
