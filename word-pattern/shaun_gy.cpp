//grandyang, beats 100%, the idea can be used to tackle isomorphic string problem too
class Solution1 {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0;
        for (string word; in >> word; ++i) {
            if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) {
                if (m1[pattern[i]] != m2[word]) return false;
            } else {
                m1[pattern[i]] = m2[word] = i + 1;
            }
        }
        return i == pattern.size();
    }
};

//
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0;
        vector<string> words;
        
        string word;
        //for (string word; in >> word;) {
        while (in>>word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size();++i) {
            m1[pattern[i]] = m2[words[i]] = i; //i+1,i okay too
        }
        for (int i = 0; i < pattern.size();++i) {
            if (m1[pattern[i]] != m2[words[i]]) return false;
        }
        return true;
        
    }
};
