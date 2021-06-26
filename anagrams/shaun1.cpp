//shaun original idea, accepted after correcting understanding of unordered_map.count function
//beats 84.4% 

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string,int> m;
        for (string s: strs) {
            string key = sortStr(s);
            m[key]++;
        }
        
        vector<string> res;
        for (string s: strs) {
            if (m[sortStr(s)] > 1) res.push_back(s);
        }
        return res;
    }
    
private:
    string sortStr(string& s) {
        if (s.empty()) return s;
        string t = s;
        sort(t.begin(), t.end());
        return t;
    }
};
