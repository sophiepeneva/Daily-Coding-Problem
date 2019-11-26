/*

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;
int* arr;

int biggestSum(){
    for(int i = n - 3; i >= 0; i-=2){
        int m = max(arr[i + 1], arr[i + 2]);
        arr[i] += arr[i + 2];
        if(i != 0){
            arr[i - 1] += m;
        }
    }
    return max(arr[0], arr[1]);
}

int main(){

    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<biggestSum();
}
