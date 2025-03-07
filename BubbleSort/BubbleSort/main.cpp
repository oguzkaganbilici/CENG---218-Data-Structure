//
//  main.cpp
//  BubbleSort
//
//  Created by Oğuz Kağan Bilici on 22.02.2025.
//

#include <iostream>
using namespace std;

void bubbleSort(int* arr, int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0; j<len-1-i; j++)
        {
            if(arr[j+1] < arr[j])
            {
                int temprorary = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temprorary;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int arr[] = {45,23, 5,7,1,2,65,78,9,233,4,6,88,3,4122,365,76,233,46};
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
