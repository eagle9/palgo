using namespace std;
#include <string>
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
/*
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left))  ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else{ left++, right--; }
        }
        return true;
    }
};
*/
class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string s) {
        // Write your code here
        if (s.size() == 0)
        {
            return true;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            while (start < end && !isalnum(s[start]))
            {
                ++start;
            }
            
            while (start < end && !isalnum(s[end]))
            {
                --end;
            }
            
            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            
            ++start;
            --end;
        }
        
        return true;
    }
};
int main()
{
        cout << "Hello World!" << endl;
}
