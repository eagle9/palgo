//shaun brute force, TLE
class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<char,int> count;
            //try to grow substring from i to n-1
            for (int j = i; j < n; ++j) {
                count[s[j]]++;
                if (isValid(count,k)) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
    
private:
    bool isValid(unordered_map<char,int>& count, int k) {
        for (auto p: count) {
            if (p.second < k) return false;
        }
        //all count >= k
        return true;
    }
};
