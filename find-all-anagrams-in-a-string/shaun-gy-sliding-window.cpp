//grandyang sliding window, shaun has the same idea, 
//not easy to get right, with match count and hash table with array
//runtime 24ms, faster than 99%, mem less than 65%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, np = p.size(), n = s.size();
        
        for (char c : p) ++m[c];
        int to_match = np;
        
        while (right < n) {
            //if s[right] is needed
            if (m[s[right]] >= 1) --to_match; //include s[right], to match 1 less
            m[s[right]]--; //update s[right] needed 1 less, if s[right] not in pattern, will be -1
            
            
            //to match == 0, means all chars in pattern matched, no more needed, record left index into answer
            if (to_match == 0) res.push_back(left);
            
            //left      right ==>
            //left    left+np-1
            //full size window now, size = np, index diff == np-1
            //remove left 
            if (right - left == np-1) {
                //if s[left] in pattern, remove it, what happens is that we need 1 more to match next time
                if (m[s[left]] >= 0) ++to_match;
                //next we need 1 more s[left], if s[left] in pattern. not in pattern, m[s[left]] == -1
                m[s[left]]++;
                //contract left edge of window
                left++;
            }
            right++; //consider next right next time
            
        }
        return res;
    }
};
