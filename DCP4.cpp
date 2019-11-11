/*

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int moveNegativeNumbersToEnd(int* arr, int n){
    int left = 0;
    int right = n - 1;
    while(left < right){
        while(right >= 0 && arr[right] <= 0){
            right--;
        }
        if(arr[left] <= 0){
            swap(arr[left], arr[right]);
            right -- ;
        }
        left++;
    }
    return right;
}

int getFirstMissingPositiveInteger(int* arr, int n){

    int endOfArray = moveNegativeNumbersToEnd(arr, n);
    for(int i = 0; i <= endOfArray; i++){
        if(abs(arr[i]) - 1 <= endOfArray){
            arr[abs(arr[i]) - 1] *= -1;
        }
    }

    for(int i = 0; i <= endOfArray; i++){
        if(arr[i] > 0){
            return i + 1;
        }
    }

    int biggest = 1;

    for(int i = 0; i <= endOfArray; i++){
       biggest = max(biggest, abs(arr[i]));
    }
    return biggest + 1;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<getFirstMissingPositiveInteger(arr, n);
}
