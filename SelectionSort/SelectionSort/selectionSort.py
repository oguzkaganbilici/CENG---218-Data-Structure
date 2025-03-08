# -*- coding: utf-8 -*-
"""
Created on Sat Mar  8 12:01:01 2025

@author: oguz.bilici
"""



def selectionSort(array):
    for i in range(0, len(array)):
        minValueIndex = i
        
        for j in range(minValueIndex + 1, len(array)):
            if array[j] < array[minValueIndex]:
                minValueIndex = j
                
        temp = array[i]
        array[i] = array[minValueIndex]
        array[minValueIndex] = temp
        
arr = [50, 20, 30, 40, 10]

selectionSort(arr)

print(arr , " ")