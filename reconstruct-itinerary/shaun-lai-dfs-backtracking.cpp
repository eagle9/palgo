//lai brute force graph and dfs with backtracking
// more intuitive than hua's 
// cutting: src to vector of dests, sort destinations
//  grow path node by node till we reach required len
//  backtracking when not success
//runtime 20ms, faster than 96%, mem less than 98%

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //graph_: a node to all its children(destinations)
        for(const auto& v2 : tickets)
            graph_[v2[0]].push_back(v2[1]);
        //sort each node's children
        for(auto& kvpair : graph_) {
            auto& dests = kvpair.second;
            std::sort(dests.begin(), dests.end());
        }
        
        const string kStart = "JFK";
        
        vector<string> path = {kStart};
        int len = 1+ tickets.size(); //if 1 ticket, how many airports? 2
        if (dfs(kStart,path, len)) return path;
        
        return {};
    }
private:
    // src -> {dst1, dest2, ..., destn}
    unordered_map<string, vector<string>> graph_;    
    
    bool dfs(const string& src, vector<string>& path, int len) {
        if (path.size() == len) return true;
        
        auto& dests = graph_[src];
        
        //try each dest in order, once used, remove it
        for (int i = 0; i < dests.size(); ++i) {
            string dest = dests[i];
            dests.erase(dests.begin() + i);
            path.push_back(dest);
            if (dfs(dest, path, len)) return true;
            path.pop_back();
            dests.insert(dests.begin()+i, dest);
            
        }
        return false;
    }
};
