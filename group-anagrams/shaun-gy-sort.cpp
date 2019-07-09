//cutting: use sort to find each word's representative, then put this word into rep's bucket
//runtime 40ms, faster than 85%, mem less than 46%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res ;
        unordered_map<string, vector<string>> m; //hash table from representative to list of strings
        for (string str : strs) {
            string key = str; //make a copy
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        for (auto p: m) {
            res.push_back(p.second);
        }
        return res;
    }
};
