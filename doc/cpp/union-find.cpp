// Hua's union find set, to be more clear
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
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] < ranks_[pu])
            parents_[pv] = pu; //smaller tree pv parent to be pu           
        else if (ranks_[pu] < ranks_[pv])
            parents_[pu] = pv;
        else { //equal rank, pv parent to be pu
            parents_[pv] = pu;
            ranks_[pu] += 1; //why update rank only this case???
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u]) //only root parent is itself
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_; //what's rank???
};
