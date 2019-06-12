/*hua union find idea, i came up the same idea(not implemented) and found it is natural to use if suggested. but if not suggested, how to get the clue to use union find? 

my first idea to use union find is to grow the ufset. that's not how ufset is used. that way ufset.find(number) will not found, why uf.find always find and compress the path at the same time!!!!
still not quite understand ranks?? what is rank???
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Redundant Connection.
*/
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);        
        parents_ = vector<int>(n + 1, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int ru = Find(u);
        int rv = Find(v);
        if (ru == rv) return false; //same set, no need to union
        
        // Meger low rank tree into high rank tree
        if (ranks_[rv] > ranks_[ru])
            parents_[ru] = rv;           
        else if (ranks_[ru] > ranks_[rv])
            parents_[rv] = ru;
        else {//same rank
            parents_[rv] = ru;
            ranks_[rv] += 1;
        }
        //union success
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal, when you do Find
        if (u != parents_[u]) //not root
            parents_[u] = Find(parents_[u]); //update parent       
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};
 
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {           
        //create ufset with all 1 to n at first, my idea is to grow
        //wont be clean
        UnionFindSet ufs(edges.size());
        
        //[[1,2], [1,3], [2,3]]
        for(const auto& edge: edges)
            if (!ufs.Union(edge[0], edge[1]))
                return edge;
        
        return {};
    }
};

