#include<iostream>
using namespace std;

int search(int a[], int target, int first, int last) {
   int location = -1;

   if (first <= last) {
      int mid = (first + last) / 2;

      if (target == a[mid])
         location = mid;
      else if (target < a[mid])
         location = search(a, target, first, mid-1);
      else {
         location = search(a, target, mid+1, last);
      }
   }

   return location;
}

int find(int a[],int length, int target) {
   int loc = search(a, target, 0, length-1);
   return loc;
}

int main() {
   int array[] =  {5, 7, 9, 13, 32, 33, 42, 54, 56, 88};
   int len = sizeof(array) / sizeof(array[0]);
   int loc = find(array,len, 55);
   cout<<loc;
   return 0;
}
