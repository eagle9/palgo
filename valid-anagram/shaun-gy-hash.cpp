//runtime 12ms, faster than 98%, mem less than 79%
//shaun gy hash table idea, accepted after 1 bug fix, forgot about len1 == len2 check
//why not check m[ch - 'a'] == 0 for all? it is okay, but we can make it return false quicker since length s == length t.  there must exist a char in s not matched by t, so < 0 check
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> m(26);
        for (char ch: s) {
            ++m[ch - 'a'];
        }
        
        for (char ch: t) {
            if (--m[ch - 'a'] < 0) return false;
        }
        return true;
    }
};

/*
Follow up

What if the inputs contain unicode characters? How would you adapt your solution to such case?

Answer

Use a hash table instead of a fixed size counter. Imagine allocating a large size array to fit the entire range of unicode characters, which could go up to more than 1 million. A hash table is a more generic solution and could adapt to any range of characters.


*/
