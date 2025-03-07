//
//  main.cpp
//  InsertionSort
//
//  Created by Oğuz Kağan Bilici on 23.02.2025.
//

#include <iostream>
using namespace std;

void insertionSort(vector<int>& arr)
{
    long len = arr.size();
    
    for(int i=1; i<len;i++)
    {
        int insert_index = i;
        int value = arr[i];
        arr.erase(arr.begin() + i);
        
        for(int j = i-1; j>=0;j--)
        {
            if(arr[j] > value)
                insert_index = j;
        }
        arr.insert(arr.begin() + insert_index, value);
    }
}

void insertionSort_v2(int* arr, int len)
{
    for(int i=1;i<len;i++)
    {
        int insert_index = i;
        int value = arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] > value)
            {
                arr[j+1] = arr[j];
                insert_index = j;
                arr[insert_index] = value;
            }
            else
                break;
        }
    }
        
}
int main(int argc, const char * argv[]) {
    vector<int> my_array = {4, 34, 25, 12, 22, 11, 90, 5};
    int arr[] = {4, 34, 25, 12, 22, 11, 90, 5};
    insertionSort(my_array);
    insertionSort_v2(arr, sizeof(arr) / sizeof(int));
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    

    return 0;
}
