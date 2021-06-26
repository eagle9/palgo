//grandyang use of bit mask to replace hashmap
//TLE brute force O(n^3)  ----> O(n^2)
//still count letters with m
//runtime 176ms, faster than 31%, mem less than 87%
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        //enumerate all possible substring from i to j
        while (i + k-1 < n) {
            //int m[26] = {0};
            vector<int> m(26);
            int mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                int t = s[j] - 'a';
                ++m[t];
                if (m[t] < k) mask |= (1 << t);  //< k, set t-th bit to 1, no change to other bits
                else mask &= (~(1 << t)); // >=k, set t-th bit to 0, no change to other bits
                if (mask == 0) { //all chars count > 3
                    res = max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
            //i++; //okay too
        }
        return res;
    }
};
