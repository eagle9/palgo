//shaun own idea
//accepted first sub
//runtime 48ms, faster than 86%, mem less than 34%
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            if (!m.count(words[i])) m[words[i]] = {i};
            else {
                m[words[i]].push_back(i);
            }
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> vi1 = m[word1];
        vector<int> vi2 = m[word2];
        int ans = INT_MAX;
        for (int i: vi1) {
            for (int j: vi2) {
                ans = min(ans, abs(i-j));
            }
        }
        return ans;
    }
private:
    unordered_map<string,vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
