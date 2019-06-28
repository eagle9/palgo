/*
grandyang idea with hash and pointers
cutting : concatenation of n words is a string of len n*m, the expected substring len is n*m
try sliding such a n*m len substring in given s
then try to match the subtring window segment by segment (len m)
runtime 208ms, faster than 56%, mem less than 53%
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (auto &a : words) ++m1[a];
        
        //try all substring of len n*m, starting from i
        // check the substring contains all words in the given list
        for (int i = 0; i <= (int)s.size() - n * m; ++i) {
            unordered_map<string, int> m2;
            int j = 0;
            //find each word of len m in the substring
            // total n words
            for (j = 0; j < n; ++j) {
                string segment = s.substr(i + j * m, m);
                //if the segment word not in m1, try next substring of len n*m
                if (m1.find(segment) == m1.end()) break;
                ++m2[segment]; //match count stored in m2
                if (m2[segment] > m1[segment]) break;
                // m2[segment] <= m1[segment]
            }
            //for all n segments, m2[segment] <= m1[segment]
            //m1 total is n, m2 total is n too
            //so at this point, found a match
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
