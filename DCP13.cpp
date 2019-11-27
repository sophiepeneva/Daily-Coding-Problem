/*

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

*/

#include<iostream>
#include<string>
#include<set>
using namespace std;

int k;
string str;

int max(int a, int b){
    return a > b ? a : b;
}

int longestSubstringWithKUniqueChars(){
    if(k <= 1){
        return k;
    }
    if(k >= str.length()){
        return str.length();
    }
    int left = 0;
    int i = 0;
    int maxLen = -1;
    set<char> unique;
    while(i < str.length()){
        unique.insert(str[i]);
        if(unique.size() > k){
            maxLen = max(maxLen, i - left);
            while(unique.size() > k){
                unique.erase(str[left]);
                left++;
            }
        }
        i++;
    }
    return maxLen == -1 ? str.length() : maxLen;
}

int main(){

    cin>>k;
    cin>>str;

    cout<<longestSubstringWithKUniqueChars();
}
