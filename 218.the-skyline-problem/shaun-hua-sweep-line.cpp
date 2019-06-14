//hua sweep line algo, shaun modified with balanced binary tree set and Event struct
//care needs to be taken to deal with two building adjacent to each other,
//check Event operator< 

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// shaun modified to make it easier to understand
//runtime 24ms, faster than 99.65%, mem less than 38%
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<Event> events;        
        hset_.clear(); //can be commented. hset_ used to store heights in bst with duplicated keys, sorted. supports insert erase and min max O(logn)
        
        for (const auto& b : buildings) {
            events.push_back(Event(b[0], b[2],1));
            events.push_back(Event(b[1], b[2],-1));
        }
        
        // Sort events by x
        sort(events.begin(), events.end());
        
        vector<vector<int>> ans;
        
        // Process all the events
        for (const auto& e: events) {            
            if (e.type == 1) {                
                if (e.height > maxHeight()) 
                    ans.push_back({e.x, e.height});
                hset_.insert(e.height);
            } else {
                hset_.erase(hset_.equal_range(e.height).first);
                if (e.height > maxHeight())
                    ans.push_back({e.x, maxHeight()});
            }            
        }
        
        return ans;
    }
private:
    struct Event{
        int x;
        int height;
        int type;
        Event(int x, int height, int type): x(x), height(height),type(type) {};
        bool operator<(Event& other) const {
            //both entering, greater height first --- draw picture, you will see
            //both leaving, smaller height first --- draw picture, you will see
            //1 entering 1 leaving, entering first -- draw picture, you will see
            
            if (x == other.x) return height*type > other.height*other.type;
            return x < other.x;
        }
    };
    int maxHeight() const {
        if (hset_.empty()) return 0;
        //return *hset_.rbegin();
        return *(--hset_.end()); //bug return *hs_.end(), now you understand why it is preferred to return *hs_.rbegin()
    }
    multiset<int> hset_;
};
