/* shaun and gy Union Find
all connected but no cycle

shaun got the idea, code accepted after 2 bug fixes, vague memory of find function
cutting: for each edge (u-v), check u and v in the same set, if same set, cycle found, return false
no cycle found, all nodes connected?  number of edges should be 1 less than number of nodes
union find is pretty neat to solve this problem 

runtime 16ms, faster than 92%, mem less than 44%
*/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n, -1);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        for (const auto& e : edges) {
            //simply union here
            int p1 = find(e[0]), p2 = find(e[1]);
            if (p1 == p2) return false;
            parent[p1] = p2; //simply union here
        }
        //exit loop, no cycle found
        return edges.size() == n - 1;
    }
    int find(int i) {
        //if (parent[i] != find(i)) parent[i] = find(i);   //bug 1, vague memory
        //if (parent[i] != i) parent[i] = find(i); //bug 2 vague memory
        //if (parent[i] != i) parent[i] = find(parent[i]);  //accepted
        while (i != parent[i]) i = parent[i]; //accepted too, this version might be easier to remember, keep going up till i == parent[i] (root)
        return i;
    }
private:
    vector<int> parent;
    //vector<int> rank; //not used for simplicity
};
