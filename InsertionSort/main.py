# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

def insertSort(array):
    for i in range(0, len(array) - 1):
        j = i+1
        while j > 0 and array[j-1] > array[j]:
            temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp
            
            j = j -1
            
            
arr = [7, 3, 5, 1]

insertSort(arr)

for i in arr:
    print(i, " ")