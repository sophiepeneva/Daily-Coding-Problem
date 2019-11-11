# Daily-Coding-Problem
/*

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

#include<iostream>
#include<stdlib.h>
#include <algorithm> 
#include<bits/stdc++.h>
#include<map>
using namespace std;

bool sumExistsInList(int k, vector<int> nums){
    map<int, int> numbers;
    for(int i = 0; i < nums.size(); i++){
        numbers[nums[i]]++;
    }
    for(int i = 0; i < nums.size(); i++){
        int target = k - nums[i];
        if((target != nums[i] && numbers.count(target) > 0) || (target == nums[i] && numbers.count(target) > 1)) {
            return true;
        }
    }
    return false;
}

int main(){
    int k, n;
    vector<int> nums;
    cin>>n>>k;
    int num;
    for(int i = 0; i < n; i++){
        cin>>num;
        nums.push_back(num);
    }
    cout<<sumExistsInList(k, nums);
    return 0;
}
