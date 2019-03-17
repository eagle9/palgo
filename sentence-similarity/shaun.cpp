//grandyang hashtable idea, shaun similar idea, runtime 12ms, faster than 100%
class Solution1 {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) return false;
        }
        return true;
    }
};
//shaun's own idea with unordered_set<string>
//runtime 12ms, faster than 100%
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_set<string> m;
        for (auto pair : pairs) {
            m.insert(pair.first + "," + pair.second);
            m.insert(pair.second + "," + pair.first);
            
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!m.count(words1[i] + "," + words2[i])
                && !m.count(words2[i] + "," + words1[i]))
                return false;
        }
        return true;
    }
};
