#include<iostream>
using namespace std;

void selectionSort(int arr[], int length) {
    for (int i=0;i<length-1;i++) {
        int minIndex = i;
        cout<<"minIndex:" << i << " arr[minIndex]: "<< arr[minIndex] <<endl;
        for (int k=i+1; k<length; k++) {
            cout<<"k:"<< k << " arr[k]:"<< arr[k]<<endl;
            if (arr[k] < arr[minIndex])
                minIndex = k;

            cout<<"new minIndex: "<<minIndex<<" arr[minIndex]:"<<arr[minIndex]<<endl;
            cout<<"-----------"<<endl;
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int len = sizeof(data) / sizeof(data[0]);

    selectionSort(data, len);

    for (int i=0;i<len;i++) {
        cout<<data[i]<<" - ";
    }
}