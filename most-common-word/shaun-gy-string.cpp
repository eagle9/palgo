//shaun has the same idea,   banned from vector to set
//not clear how to deal with non alpha chars, convert them to ' '
//tokenizer and hash table
//runtime 4ms, faster than 97%, mem less than 45%
class Solution1 {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> strCnt;
        int mx = 0;
        for (auto &c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string token = "", res = "";
        while (iss >> token) {
            //only consider token not in banned set
            if (!ban.count(token) && ++strCnt[token] > mx) {
                mx = strCnt[token];
                res = token;
            }
        }
        return res;
    }
};
//shaun use getline to tokenize streamstream
//runtime 4ms, faster than 97%, mem less than 45%
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> strCnt;
        int mx = 0;
        for (auto &c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        stringstream iss(paragraph);
        string token = "", res = "";
        while (getline(iss, token, ' ')) {
            if (token == "") continue; //add this when you use getline
            //only consider token not in banned set
            if (!ban.count(token) && ++strCnt[token] > mx) {
                mx = strCnt[token];
                res = token;
            }
        }
        return res;
    }
};
