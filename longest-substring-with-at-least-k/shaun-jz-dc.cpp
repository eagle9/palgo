/*令狐冲
更新于 3/24/2019, 11:59:40 PM
贪心法 + 递归。
如果一个字符出现次数 < k 说明最长的要么在它左边，要么在它右边（不可能跨过他），从它拆开往下递归计算即可。*/
//linghuchong idea, shaun read and understand
//runtime 4ms, faster than 98%, mem less than 32%
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> counter(26,0);
        for (char c: s) counter[c-'a']++;
        
        int left = 0, len = s.size();
        int longest = 0;
        for (int i = 0; i < len; i++) {
            if (counter[s[i] - 'a'] < k) {
                //look in substring from left to i-1
                int sub_longest = longestSubstring(s.substr(left, i-left), k);
                longest = max(longest, sub_longest);
                left = i + 1;
            }
        }
        
        if (left == 0) { //left not changed, all char count >= k, so entire string 
            return len;
        }
        
        //left will be the max i where char count < k, makes sense
        //done search from i's left, now i' right
        int sub_longest = longestSubstring(s.substr(left), k);
        longest = max(longest, sub_longest);
        
        return longest;
    }
};

