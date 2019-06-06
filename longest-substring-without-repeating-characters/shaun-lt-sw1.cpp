//lt sliding window
//runtime 48ms, faster than 26%, mem less than 45%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> set1; //set of chars as the slide window
        int ans = 0, left = 0, right = 0;
        while (left < n && right < n) {
            // try to extend the range [left, right]
            if (!set1.count(s[right])){
                set1.insert(s[right]);
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                set1.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
