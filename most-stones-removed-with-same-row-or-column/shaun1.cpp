//shaun's own idea with union find hint

//first sub MLE
//second sub stack-overflow
//third sub accepted 
//runtime 152ms, faster than 16%, mem less than 46%
//4th sub, time from N^N to N, 
//runtime 80ms, faster than 53%, mem less than 16%
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //int NN = N*N;
        //parent.resize(NN);   //bug1  ----MLE
        //rank.resize(NN);
        for (auto vi: stones) {
        	int xy = vi[0]*N + vi[1]; //xy is cordinate id
        	parent[xy] = xy;
        	rank[xy] = 1;
        }
        
        int n = stones.size();
        /*
        for (int i = 0; i < n; ++i) {
        	int p1 = stones[i][0]*N + stones[i][1];
        	for (int j = i+1; j < n; ++j) {
        		int p2 = stones[j][0]*N + stones[j][1];
        		if (isConnected(p1,p2)) Union(p1,p2);
        	}
        }*/
        unordered_map<int,vector<int>> mr, mc; //row index to stone ids
        for (int i = 0; i < n; ++i) {
            int x = stones[i][0], y = stones[i][1];
            int p = x*N + y;
            mr[x].push_back(p);
            mc[y].push_back(p);
        }
        
        for (auto kv: mr) {
            vector<int> points = kv.second;
            for (int i = 1; i < points.size(); ++i) {
                Union(points[0], points[i]);
            }
        }
        for (auto kv: mc) {
            vector<int> points = kv.second;
            for (int i = 1; i < points.size(); ++i) {
                Union(points[0], points[i]);
            }
        }
        //now find each cluster and its size
        int ans = 0;
        for (auto p: final_parents) {
            ans += rank[p]-1;
        }
        return ans;
        
    }
private:
	int N = 10000;
    
	//vector<int> parent(N*N); ---- bug comiler error, N is not a type
    //vector<int> parent;
    unordered_map<int,int> parent;
	//vector<int> rank(N*N);
    //vector<int> rank;
    unordered_map<int,int> rank;
    
	unordered_set<int> final_parents;
	int Find(int xy) {
		//if (parent[xy] != xy) parent[xy] = Find(xy); //bug segmentation force, stackoverflow
        if (parent[xy] != xy) parent[xy] = Find(parent[xy]);
		return parent[xy];
	}
	bool Union(int u, int v) {
		int pu = Find(u), pv = Find(v);
		if (pu == pv) return false; //no need to union
		if (rank[pu] <= rank[pv]) {
			parent[pu] = pv;
			rank[pv] += rank[pu];
			if (final_parents.count(pu)) final_parents.erase(pu);
			final_parents.insert(pv);
		}else if (rank[pv] < rank[pu]) {
			parent[pv] = pu;
			rank[pu] += rank[pv];
			if (final_parents.count(pv)) final_parents.erase(pv);
			final_parents.insert(pu);
		}
		return true;

	}
	bool isConnected(int p1, int p2) {
		int x1 = p1/N, y1 = p1%N;
		int x2 = p2/N, y2 = p2%N;
		if (x1 == x2 || y1 == y2) return true;
		return false;
	}
};
