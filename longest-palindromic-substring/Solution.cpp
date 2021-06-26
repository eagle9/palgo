//g++ -std=c++11 Solution.cpp
using namespace std;
#include <cstring>   //for memset
#include <string> 
#include <iostream>  //for cout and endl
class Solution {
public:
    int longestPalindrome(string s) {
        int charStatArray[52];
        int oneTimeOddCount = 0;
        int evenCount = 0;
    
        // zero clearing of the array
        memset(charStatArray, 0, sizeof(charStatArray));
    
        // keep the times of appearance of each character in the array
        // shaun: c++ now catches up java, now you can loop each char in a string 
        for (char ch: s) {
            if (ch >= 97) {  //shaun: why 97?  97 is asc ii value for 'a'
                charStatArray[26 + ch - 'a']++;  //shaun: why starting with 26? the problem specifies case sensitive
            }
            else {
                charStatArray[ch - 'A']++;
            }
        }
    
        // the answer is the count of characters that has even number of appereances.
        // for characters that has odd number of appereances,
        // their appereances minus 1 will make their apperances even.
        // And finally we can put an unused character in the middle of the palindrome
        // (if there is any).
        for (int cnt: charStatArray) {
            if (cnt != 0) {
                if (cnt % 2 == 0) {
                    evenCount += cnt;
                } else {
                    if (cnt == 1) {
                        oneTimeOddCount++;
                    }
                    else {  //cnt > 1 and odd
                        evenCount += cnt - 1;
                        oneTimeOddCount++;
                    }
                }
            }
        }
    
        //shaun: if there are multiple odd count char, only consider 1. this makes sense now.
        return oneTimeOddCount > 0 ? 1 + evenCount : evenCount;
    }
};
int main() {
    cout << "working" << endl;
}
