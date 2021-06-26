//shaun's own idea with hash table and heap
//cutting: get char and count, then use a heap 
//accepted after 1 bug fix, 
//runtime 16ms, faster than 76%, mem less than 76%
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m; 
        for (char ch: s) {
            m[ch]++;
        }
        priority_queue<pair<int,char>> maxHeap;
        for (auto kv: m) {
            maxHeap.push(make_pair(kv.second, kv.first));
        }
        string res;
        while (!maxHeap.empty()){
            auto p = maxHeap.top();
            int count = p.first;
            char ch = p.second;
            res.append(count,ch);
            maxHeap.pop();
        }
        return res;
    }
};
