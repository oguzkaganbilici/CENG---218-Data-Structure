#include<iostream>
using namespace std;

void insertionSort(int arr[], int l) {
    for (int i=1; i<l; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int len = sizeof(data) / sizeof(data[0]);

    insertionSort(data, len);

    for (int i=0;i<len;i++) {
        cout<<data[i] << " - ";
    }
}