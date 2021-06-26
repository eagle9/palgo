//shaun with lt union find idea
//proof read all 
//runtime 28ms, faster than 99%, mem less than 13%


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        //init parent and rank
        parent.resize(20000);
        rank.resize(20000);
        for (int i = 0; i < 20000; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        //try to deal with 1d integer, for a stone at (i,j), connect i and j
        for (auto vi: stones) {
        	int i  = vi[0], j = vi[1]+10000;
            Union(i,j);
        }
        
        unordered_set<int> seen; //record clusters
        for (vector<int> vi: stones) {
            int i = vi[0];
            seen.insert(Find(i));
        }
        return stones.size() -seen.size();
        
    }
private:
	int N = 20000;
    vector<int> parent;
    
    vector<int> rank;
    
	int Find(int xy) {
		//if (parent[xy] != xy) parent[xy] = Find(xy); //bug segmentation force, stackoverflow
        if (parent[xy] != xy) parent[xy] = Find(parent[xy]);
		return parent[xy];
	}
	bool Union(int u, int v) {
		int pu = Find(u), pv = Find(v);
		if (pu == pv) return false; //no need to union
		if (rank[pu] < rank[pv]) {
			parent[pu] = pv;
		}else if (rank[pv] < rank[pu]) {
			parent[pv] = pu;
		}else {
            parent[pu] = pv;
            rank[pv]++;
        }
		return true;

	}
	
};
