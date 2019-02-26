/*
huahua hash table and heap
Runtime: 20 ms, faster than 99.61% of C++ online submissions for Top K Frequent Words.
Memory Usage: 12 MB, less than 64.10% of C++ online submissions for Top K Frequent Words.
*/
class Solution {
private:
    typedef pair<string, int> Node;
    typedef function<bool(const Node&, const Node&)> Compare;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const string& word : words)
            ++count[word];
        
        Compare comparator = [](const Node& a, const Node& b) {
            // order by alphabet ASC
            if (a.second == b.second) 
                return  a.first < b.first;
            // order by freq DESC
            return a.second > b.second;
        };
        
        // Min heap by frequency
        priority_queue<Node, vector<Node>, Compare> q(comparator);
        
        // O(n*logk)
        for (const auto& kv : count) {
            q.push(kv);
            if (q.size() > k) q.pop();
        }
        
        vector<string> ans;
        
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

