//shaun own idea and code, accepted after 1 typo fix
//runtime 32ms, faster than 98%, mem less than 88%
class Solution {
public:
    int firstUniqChar(string s) {
        //Note: You may assume the string contain only lowercase letters.
        //vector<int> m(26);
        int m[26] = {0};
        for (char ch: s) m[ ch - 'a']++;
        
        for (int i = 0; i < s.length(); ++i) {
            if (m[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
