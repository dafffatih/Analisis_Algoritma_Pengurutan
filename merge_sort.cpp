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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_terbalik(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort_terbalik(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort_terbalik(arr, left, mid);
    mergeSort_terbalik(arr, mid + 1, right);
    merge_terbalik(arr, left, mid, right);
}

void sort(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void sort_terbalik(int arr[], int n){
    auto awal = chrono::high_resolution_clock::now();
    mergeSort_terbalik(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen setelah dishorting terbalik :" << endl;
    print_array(arr, n);
    cout << endl << "Waktu eksekusi: " << durasi << " microseconds" << endl;
}

void merge_sort(int arr[], int n){
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
    cout << "|    MERGE SORT    |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    int pilih, n;
    cout << "Pilih jumlah elemen yang diinginkan : "; cin >> n;
    int arr[n];
    list_array(arr, n);
    merge_sort(arr, n);
}