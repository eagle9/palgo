//shaun's own idea after union find hint, accepted after fixing 2 bugs
//runtime 20ms, faster than 23.60%, mem less than 9%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; //bug 2 fix, add this line to return 0 for empty array
        for (int i: nums) {
            //critical: only init union find set with unique numbers in the array
            if (parent.find(i) == parent.end()) { //bug 1 fix: add this line to prevent repeated numbers in nums
                parent[i] = i;
                rank[i] = 0;
            }
        }
        for (auto p: parent) {
            int i = p.first;
            if (parent.find(i-1) != parent.end()) UNION(i,i-1); //if neighboring number in uf set, union them
            if (parent.find(i+1) != parent.end()) UNION(i,i+1);
        }
        
        //now figure out each cluster size
        unordered_map<int,int> bucket;
        int ans = INT_MIN;
        
        for (auto p: parent) {
            int i = p.first;
            int root = find(i);
            //int root = parent[i]; 
            bucket[root]++;
            ans = max(ans,bucket[root]);
        }
        return ans;
        
    }
private:
    unordered_map<int,int> rank; //number to its rank
    unordered_map<int,int> parent; //number to its parent number
    bool UNION(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;
        
        if (rank[pi] <= rank[pj]) {
            parent[pi] = pj;
            rank[pj]++;
        }else {
            parent[pj] = pi;
            rank[pi]++;
        }
        return true;
    }
    int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
};
