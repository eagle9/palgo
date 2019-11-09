//shaun own c++ code with cursor type dfs hint
//tle
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<bool> used(bikes.size());
        dfs(workers, bikes, 0, used, 0);
        return minSum;
    }
    
private:
    int minSum = INT_MAX;
    void dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes,
            int cur, //cur index of workers
            vector<bool>& used, //bike index used or not
            int sumDistance //current sum of distance
            ){
        if (cur == workers.size()) {
            minSum = min(minSum, sumDistance);
            return;
        }
        
        if (sumDistance > minSum) return;
        
        //now for worker[cur], try to assign all bikes that not used yet
        for (int i = 0; i < used.size(); ++i) {
            if (used[i]) continue; //skip used bike
            used[i] = true;
            //assign bikes[i] to workers[cur]
            dfs(workers, bikes, cur+1, used,sumDistance + getDist(workers[cur], bikes[i]));
            //back track, release bikes[i]
            used[i] = false;
        }
        
    }
    
    //get manhattan distance
    int getDist(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
};
