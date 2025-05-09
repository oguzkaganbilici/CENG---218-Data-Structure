#include<iostream>
using namespace std;

void mergeArray(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i=0; i<n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i=0; i<n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
        }
    }

    while (i<n1) {
        arr[k++] = L[i++];
    }
    while (j<n2) {
        arr[k++] = R[j++];
    }
    delete[] L, delete[] R;
}

void mergeSortArray(int arr[], int left, int right) {
    if (left<right) {
        int mid = left + (right - left)/2;
        mergeSortArray(arr, left, mid);
        mergeSortArray(arr, mid+1, right);
        mergeArray(arr, left, mid, right);
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int length = sizeof(data) / sizeof(data[0]);
    mergeSortArray(data, 0, length-1);

    for (int i=0;i<length;i++) {
        cout<<data[i]<<" ";
    }
}