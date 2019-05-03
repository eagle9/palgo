//shaun's own idea using heap, accepted after debugging failed cases
//when freq ties how you break the tie???
//two ways to define customized priority_queue
//runtime 20ms, faster than 93%, mem less than 99%
struct entry {
    int freq;
    string word;
    entry(int freq, string word) {
        this->freq = freq;
        this->word = word;
    }
    
    //bool operator< (entry& other) const { //compiler error
    bool operator<(entry other) const {
        if (freq == other.freq) return word < other.word;
        return freq > other.freq;  //greater freq in front
    }
};
struct eCompare {
    bool operator () (entry& a, entry& b) const {
        if (a.freq == b.freq) return a.word < b.word;
        return a.freq > b.freq;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for (string w: words) {
            m[w]++;
        }
        //priority_queue<entry, vector<entry>, eCompare> minHeap; //min freq at the top
        priority_queue<entry> minHeap;
        for (auto p: m) {
            minHeap.push(entry(p.second, p.first));
            while (minHeap.size() > k) minHeap.pop();
        }
        vector<string> res;
        while (!minHeap.empty()) {
            res.insert(res.begin(),minHeap.top().word);
            minHeap.pop();
        }
        return res;
    }
};
