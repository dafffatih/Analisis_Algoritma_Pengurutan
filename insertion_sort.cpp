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

void sort(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void sort_terbalik(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting terbalik :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void insertion_sort(int arr[], int n){
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
    cout << "|  INSERTION SORT  |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    int pilih, n;
    cout << "Pilih jumlah elemen yang diinginkan : "; cin >> n;
    int arr[n];
    list_array(arr, n);
    insertion_sort(arr, n);
}