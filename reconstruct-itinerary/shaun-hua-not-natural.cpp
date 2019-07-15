//hua idea, cutting, contruct an n-ary tree from the tickets, from a1/src to its children/dests, sort dests in lex order
// postorder, once a child is visited, remove it
//problem assumes that there exists solution. all tickets will be included in the itinerary. all edges will be visisted. for postorder and reverse details, you have to draw a sample to figure out
//runtime 20ms, faster than 96%, mem less than 93%
//don't know how to come up hua's postorder and reverse idea, not intuitive
/*
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]

   JFk: (ATL), SFO
   SFO: ATL
   ATL: JFK, SFO
   
   JFK -> ATL 

*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //route_.clear();
        //trips_.clear();
        
        //trips_: a node to all its children(destinations)
        for(const auto& v2 : tickets)
            trips_[v2[0]].push_back(v2[1]);
        //sort each node's children
        for(auto& kvpair : trips_) {
            auto& dests = kvpair.second;
            std::sort(dests.begin(), dests.end());
        }
        
        const string kStart = "JFK";
        
        postorder(kStart);
        
        //return vector<string>(route_.crbegin(), route_.crend());
        reverse(route_.begin(), route_.end());
        return route_;
    }
private:
    // src -> {dst1, dest2, ..., destn}
    unordered_map<string, deque<string>> trips_;    
    // ans (reversed)
    vector<string> route_;
    
    void postorder(const string& src) {
        auto& dests = trips_[src];
        while (!dests.empty()) {
            // Get the smallest child/dest, and pop it
            const string dest = dests.front(); dests.pop_front();
            // Visit dest
            postorder(dest);
            //when you done with posterorder dest, what's next? 
            //  dests.front() again, so while !dests.empty() make senses
        }
        // at this point, we are done with all its children in lex order
        //so we Add current node to the route
        route_.push_back(src);
    }
};
