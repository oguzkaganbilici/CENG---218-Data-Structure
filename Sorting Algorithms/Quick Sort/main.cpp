#include<iostream>
using namespace std;

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high]; // son eleman pivot olarak sec
    int i = (low - 1); // kucuk elemanın indeksini takip et

    for (int j = low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp_ = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp_;

    return (i+1);
}

void quickSortArray(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high);
        quickSortArray(arr, low, pi-1);
        quickSortArray(arr, pi+1, high);
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int len = sizeof(data) / sizeof(data[0]);

    quickSortArray(data, 0, len-1);

    for (int i=0; i<len; i++) {
        cout<<data[i]<< " ";
    }
}