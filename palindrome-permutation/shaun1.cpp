//shaun's idea, accepted after fixing some typo
//runtime 4ms, faster than 100%
class Solution1 {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> m; 
        for (char c: s) m[c]++;  
        int count_odd = 0; 
        for (auto p: m) { 
            if (p.second % 2 == 1) count_odd++; 
        } 
        if (s.size() % 2 == 0){ 
            if (count_odd == 0) return true; 
            else return false; 
        }  
        //odd len  
        if (count_odd == 1) return true; 
        else return false; 
    }
};

//modified from 1 when i used this at palindrome permutation ii
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Palindrome Permutation.
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> m; 
        for (char c: s) m[c]++;
        int count_odd = 0;
        for (auto p: m) {
            if (p.second % 2 == 1) count_odd++;
        }
        if (s.size() % 2 == 0 && count_odd != 0) return false; //no palin permu
        if (s.size() % 2 == 1 && count_odd != 1) return false; //no palin permu
        return true;
    }
};
