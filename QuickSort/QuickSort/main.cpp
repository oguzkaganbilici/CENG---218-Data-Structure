//
//  main.cpp
//  QuickSort
//
//  Created by Oğuz Kağan Bilici on 23.02.2025.
//

#include <iostream>
using namespace std;

int partition(int* arr, int low,int high)
{
    /*
     diziyi pivota göre 2 alt gruba böler
     
    */
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j=low; j<high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSort(int* arr, int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    quickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    
    for(int i: arr)
        cout<<i<<" ";
    return 0;
}
