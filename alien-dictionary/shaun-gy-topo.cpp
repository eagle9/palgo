/*
grandyang topo sort with bfs
shaun read, modified, and understand
cutting angle, derive orders of two chars, then use topo sorting

runtime 4ms, faster than 93%, mem less than 68%
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char>> orders; //orders of two pairs
        unordered_set<char> ch; //char set of the language
        
        vector<int> in(256, 0); //in degree of each char
        queue<char> q; //queue for topo sort bfs
        
        
        for (auto a : words) ch.insert(a.begin(), a.end());
        
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            //derive order of two chars from two consecutive words in the given list
            int minLen = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < minLen; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    orders.insert(make_pair(words[i][j], words[i + 1][j]));
                    break; // after j no valid order can be derived
                }
            }
            //if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (auto p : orders) ++in[p.second]; //a.first -> a.second
        
        string res = ""; //start topo sorting, find 0 inegree nodes
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                res += a;
            } 
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto p : orders) {
                if (p.first == c) {
                    --in[p.second];
                    if (in[p.second] == 0) {
                        q.push(p.second);
                        res += p.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};

