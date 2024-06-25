#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

void list_array(int arr[],const int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    srand(time(nullptr));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(i < 10 || i >= n - 2){
            cout << arr[i] << " ";
        } else if(i == 10){
            cout << "... ";
        } else{
            continue;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_terbalik(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort_terbalik(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_terbalik(arr, low, high);

        quickSort_terbalik(arr, low, pi - 1);
        quickSort_terbalik(arr, pi + 1, high);
    }
}

void sort(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void sort_terbalik(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    quickSort_terbalik(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting terbalik :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void quick_sort(int arr[], int n){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "elemen sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl;
    int temp_arr[n];
    for(int i = 0; i < n; i++){
        temp_arr[i] = arr[i];
    }
    cout << "------------------------------------------------------" << endl;

    cout << "sorting elemen teracak dari kecil ke besar" << endl;
    sort(temp_arr, n);
    cout << "------------------------------------------------------" << endl;

    cout << "sorting elemen teracak dari besar ke kecil" << endl;
    sort_terbalik(arr, n);
    cout << "------------------------------------------------------" << endl;

    cout << "sorting elemen yang sudah tersorting" << endl;
    sort(temp_arr, n);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main(){
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|    QUICK SORT    |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    int pilih, n;
    cout << "Pilih jumlah elemen yang diinginkan : "; cin >> n;
    int arr[n];
    list_array(arr, n);
    quick_sort(arr, n);
}