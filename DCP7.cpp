/*

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

*/

#include<iostream>
#include<string>

using namespace std;

int waysToDecode(string msg, int pos, int letter){
    if(letter > 26){
        return 0;
    }
    if(pos >= msg.size()){
        return 1;
    }
    if(letter >= 10){
        int next = msg[pos] - '0';
        return waysToDecode(msg, pos + 1, next);
    } else if( msg[pos] - '0' == 0){
        return waysToDecode(msg, pos + 1, letter*10 + (msg[pos] - '0'));
    }else {
        return waysToDecode(msg, pos + 1, letter*10 + (msg[pos] - '0')) + waysToDecode(msg, pos + 1, msg[pos] - '0');
    }
}

int waysToDecode(string msg){
    return waysToDecode(msg, 1, msg[0] - '0');
}
 
int main(){

    cout<<waysToDecode("27")<<endl;

    return 0;
}
