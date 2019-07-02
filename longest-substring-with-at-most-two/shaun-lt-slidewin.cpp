//lt sliding window with two pointers hash table, shaun read and understand, code from idea
//cutting, substring with a condition, naturally sliding window
// distinct chars in the window, naturally hashmap
// in order to contract left, we need index, so char to index hashmap
//runtime 12ms, faster than 78.60%, mem less than 21%
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n ==0 ) return 0;

        // sliding window left and right pointers
        int left = 0, right = 0;
        // hashmap character -> its rightmost position 
        // in the sliding window
        unordered_map<char,int> m;

        int longest = 1;

        for (; right < n; right++) {
            // add new character and move right pointer
            m[s[right]] = right;

            // slidewindow contains k+1 characters
            if (m.size() == 3) {
                // delete the leftmost character
                int min_idx = INT_MAX;
                for (auto p: m) min_idx = min(min_idx, p.second);
                
                m.erase(s[min_idx]);
                // move left pointer of the slidewindow
                left = min_idx + 1;
            }

            longest = max(longest, right - left+1);
            
        }
        return longest;
    }
};
