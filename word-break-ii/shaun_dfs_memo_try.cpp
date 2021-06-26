//shaun own try with dfs memo, break s with word in dict, s = word + suffix, recur suffix
//runtime 28ms, faster than 48%
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        //unordered_map<string,vector<string>> memo;
        //return helper(s, dict,memo);
        return helper(s,dict);
        
    }
private:
    unordered_map<string,vector<string>> memo;
    //TLE before I added & before memo, better use memo as private member
    //vector<string> helper(string s, unordered_set<string>& dict, unordered_map<string,vector<string>>& memo) {
    vector<string> helper(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo.at(s);
        vector<string> res;
        //if (s.length() == 0) {
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        
        for (string word: dict) {
            //break s with word len, s = word + suffix
            int len = word.length();
            string pref = s.substr(0,len);
            if (pref != word) continue;
            //pref == word now
            string suffix = s.substr(len);
            //recur the smaller suffix, recur with memo does not require specific order, while dp require strict bottom to top order
            //vector<string> res1 = helper(suffix,dict,memo);
            vector<string> res1 = helper(suffix,dict);
            for (string br: res1) {
                //word + " " + br
                if (br.length())
                    res.push_back(word + " " + br);
                else 
                    res.push_back(word);
            }
        }
        
        return memo[s] = res;
    }
};
