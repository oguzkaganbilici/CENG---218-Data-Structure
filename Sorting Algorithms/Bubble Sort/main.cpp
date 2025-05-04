#include<iostream>
using namespace std;

void bubbleSort(int arr[], int l) {
    for (int i=0;i<l;i++) {
        for (int k=0; k<l-i-1;k++) {
            if (arr[k+1] < arr[k]) {
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int len = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, len);

    for (int i=0;i<len;i++) {
        cout<<data[i] << " - ";
    }
}