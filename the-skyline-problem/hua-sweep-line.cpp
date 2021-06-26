//hua sweep line algo, with balanced binary tree set, Event represented by pair<int,int>
//care needs to be taken to deal with two building adjacent to each other

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// shaun modified to make it accepted by changed function signature
//runtime 36ms, faster than 73%, mem less than 48%
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event; 
        // events,  x,   h
        vector<Event> es;        
        hs_.clear();
        
        for (const auto& b : buildings) {
            es.push_back(make_pair(b[0], b[2]));
            es.push_back(make_pair(b[1], -b[2]));
        }
        
        // Sort events by x
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<vector<int>> ans;
        
        // Process all the events
        for (const auto& e: es) {            
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);
            
            if (entering) {                
                if (h > this->maxHeight()) 
                    ans.push_back({x, h});
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.push_back({x, this->maxHeight()});
            }            
        }
        
        return ans;
    }
private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    multiset<int> hs_;
};
