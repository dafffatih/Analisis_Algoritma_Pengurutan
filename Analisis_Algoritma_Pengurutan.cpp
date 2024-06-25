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

void buble_sort(int arr[], int n){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "BUBBLE SORT" << endl << endl;
    cout << "elemen array sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    auto awal = chrono::high_resolution_clock::now();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto akhir = chrono::high_resolution_clock::now();
    long int durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen array setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    cout << "Waktu eksekusi: " << durasi << " microseconds" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void insertion_sort(int arr[], int n) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "INSERTION SORT" << endl << endl;
    cout << "elemen array sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

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
    auto durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen array setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    cout << "Waktu eksekusi: " << durasi << " microseconds" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void selection_sort(int arr[], int n) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "INSERTION SORT" << endl << endl;
    cout << "elemen array sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    auto awal = chrono::high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[temp]) {
                temp = j;
            }
        }
        swap(arr[i], arr[temp]);
    }
    auto akhir = chrono::high_resolution_clock::now();
    auto durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen array setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    cout << "Waktu eksekusi: " << durasi << " microseconds" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

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

    delete[] L;
    delete[] R;
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int n) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "INSERTION SORT" << endl << endl;
    cout << "elemen array sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    auto awal = chrono::high_resolution_clock::now();
    merge_sort(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    auto durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen array setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    cout << "Waktu eksekusi: " << durasi << " microseconds" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int n) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "INSERTION SORT" << endl << endl;
    cout << "elemen array sebelum dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    auto awal = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto akhir = chrono::high_resolution_clock::now();
    auto durasi = chrono::duration_cast<chrono::microseconds>(akhir - awal).count();

    cout << "elemen array setelah dishorting :" << endl;
    print_array(arr, n);
    cout << endl << endl;

    cout << "Waktu eksekusi: " << durasi << " microseconds" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main(){
    int pilih, n;
    bool exit = false;
    cout << "Pilih jumlah elemen yang diinginkan : "; cin >> n;
    int arr[n];
    list_array(arr, n);
    while(!exit){
        cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "ALGORITMA PENGURUTAN" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "Pilih metode sorting yang diinginkan : "; cin >> pilih;
        cout << endl;

        switch (pilih)
        {
        case 1:
            buble_sort(arr, n);
            break;
        case 2:
            insertion_sort(arr, n);
            break;
        case 3:
            selection_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, n);
            break;
        case 5:
            quick_sort(arr, n);
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            exit = true;
            break;
        }

    }
}
