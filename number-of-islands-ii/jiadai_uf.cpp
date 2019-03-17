//jiadai uf idea, runtime 100ms, faster than 100%
//shaun deep read and modified, understood
//clever to convert m x n grid to 0,1 ... mxn-1, with id = r*n + c
//clever no2, parent[id] = -1, default uf init parent[id] = id
class Solution1 {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int k = positions.size(); //number of lands
        
        vector<int> parent(m * n, -1);
        /*vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};*/
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        int count = 0;
        vector<int> result(k); //allocate all, result[k] access faster, push_back overlead
        //for each land
        for (int i = 0; i < k; ++i) {
            int r = positions[i].first;
            int c = positions[i].second;
            int id = r * n + c;
            if (parent[id] == -1) {
                parent[id] = id;
                ++count;
                //union all its 4 neighbors
                for (vector<int>& d: dirs ) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    int idnew = nr*n + nc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && parent[idnew] != -1) {
                        int root1 = findParent(parent, id);
                        int root2 = findParent(parent, idnew);
                        if (root1 != root2) {
                            --count;
                            parent[root2] = root1;
                        }
                    }
                }
            }
            result[i] = count;
        }
        return result;
    }
    
private:
    //vector<int> parent_; // could not declare as member 
    int findParent(vector<int>& parent, int i) {
        if (parent[i] != i) { //not root
            parent[i] = findParent(parent,parent[i]);
        }
        return parent[i];
        /*
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;*/
    }
};

//stack-overflow when i tried to use pair<int,int> as key
//it is clumsy to use pair<int,int> as key, only map accepts it as key
//unordered_map won't accept pair as key
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int k = positions.size(); //number of lands
        
        //unordered_map can not use pair<int,int> as key, but map okay
        map<pair<int,int>,pair<int,int>> parent;
        const pair<int,int> npair = make_pair(-1,-1);
        for (auto& p: positions) parent[p] = npair;
        
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        int count = 0;
        vector<int> result(k); //allocate all, result[k] access faster, push_back overlead
        //for each land
        for (int i = 0; i < k; ++i) {
            pair<int,int> pair1 = positions[i];
            
            if (parent[pair1] == npair) {
                parent[pair1] = pair1;
                ++count;
                //union all its 4 neighbors
                for (vector<int>& d: dirs ) {
                    int nr = pair1.first + d[0];
                    int nc = pair1.second+ d[1];
                    pair<int,int> pair2 = make_pair(nr,nc);
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && parent[pair2] != npair) {
                        pair<int,int> root1 = findParent(parent, pair1);
                        pair<int,int> root2 = findParent(parent, pair2);
                        if (root1 != root2) {
                            --count;
                            parent[root2] = root1;
                        }
                    }
                }
            }
            result[i] = count;
        }
        return result;
    }
    
private:
    //vector<int> parent_; // could not declare as member 
    pair<int,int> findParent(map<pair<int,int>,pair<int,int>>& parent, pair<int,int>& i) {
        if (parent[i] != i) { //not root
            parent[i] = findParent(parent,parent[i]);
        }
        return parent[i];
        /*
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;*/
    }
};
