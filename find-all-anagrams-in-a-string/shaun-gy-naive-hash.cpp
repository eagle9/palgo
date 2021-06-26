//grandyang and shaun naive matching with hashmap
//runtime 1192ms, faster than 5%, mem less than 5%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(128, 0);
        
        int ns = s.size(), np = p.size(), i = 0;
        for (char c : p) ++m[c];
        while (i < ns) {
            vector<int> tmp = m; //copy the hash map
            //match [i, i+np) to string p anagram
            bool match = true;
            for (int j = i; j < i + np; ++j) {
                if (--tmp[s[j]] < 0) {
                    match = false;
                    break;
                }
            }
            if (match) {
                res.push_back(i); 
            }
            ++i;
        }
        return res;
    }
};
