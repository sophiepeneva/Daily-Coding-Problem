/*

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

*/

#include<iostream>

using namespace std;

int n;

int getWaysOfClimbing(int at){
    if(at >= n - 1){
        return 1;
    }
    return getWaysOfClimbing(at + 1) + getWaysOfClimbing(at + 2);
}

int main(){
    cin >> n;
    cout<<getWaysOfClimbing(0);
}
 
