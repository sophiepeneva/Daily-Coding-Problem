/*

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    int* from = new int[n];
    int* to = new int[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        from[i] = 1;
        to[i] = 1;
    }

    for(int i = 1; i < n; i++){
        to[i] = to[i-1]*arr[i-1];
    }

    for(int i = n - 2; i >= 0; i--){
        from[i] = from[i+1]*arr[i+1];
    }

    for(int i = 0; i < n; i++){
        arr[i] = to[i]*from[i];
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
