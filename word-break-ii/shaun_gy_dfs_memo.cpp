//shaun halfway change to grandyang dfs memo, runtime 20ms, faster than 77%
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo.at(s);
        
        vector<string> res;
        if (s.length() == 0) {
            res.push_back("");
            return res;
            //return {""}; //accepted
        }
        
        for (string word: wordDict) {
            //break s with word len, s = word + suffix
            int len = word.length();
            string pref = s.substr(0,len);
            if (pref != word) continue;
            //pref == word now
            string suffix = s.substr(len);
            //recur the smaller suffix, recur with memo does not require specific order, while dp require strict bottom to top order
            vector<string> res1 = wordBreak(suffix,wordDict);
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
private:
    unordered_map<string,vector<string>> memo;
};
