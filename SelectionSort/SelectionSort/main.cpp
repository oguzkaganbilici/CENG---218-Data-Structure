//
//  main.cpp
//  SelectionSort
//
//  Created by Oğuz Kağan Bilici on 22.02.2025.
//

#include <iostream>
using namespace std;

void selectionSort(vector<int>& arr)
{
    long len = arr.size();
    
    for(int i=0;i<len-1;i++)
    {
        int minIndex = i;
        for(int j=i; j<=len-1;j++)
        {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void selectionSort_v2(vector<int>& arr)
{
    long len = arr.size();
    for(int i=0;i<len;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr = {3,13,5,6,2,56,23,68,9,0,45,34,6,324,3,34,6,63,643,45,7,8,3432,4};
    selectionSort_v2(arr);
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
