//lt optimized sliding window with two pointers, no erase of hash map/set
//runtime 12ms, faster than 97%, mem less than 77%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char,int> m; // current index of character
        //use index no need to erase hash map items any more
        // try to extend the range [left, right]
        for (int right = 0, left = 0; right < n; right++) {
            if (m.count(s[right])) {  //found repeating char
                left = max(m[s[right]]+1, left); //reset left
            }
            ans = max(ans, right - left + 1);
            m[s[right]] = right;
        }
        return ans;
    }
};
