/*
worker, bike such that mdistance is the shorted, break tie with smaller worker index
for each worker, 
  min_dist = INT_MAX;
  int ib = -1; 
  for each bike {
     dist = get_dist(worker,bike)
     if (dist < min_dist)  {
        min_dist = dist;
        ib = j; //bike index
     }
  }
  ans[i] = ib;
     
ans[i] store bike index that i-th worker assigned to
shaun init idea without considering breaking the tie, obviously you need to consider to write a comparator for sorting, then assign work with bike, then track if a worker/bike is assigned and not reuse them.
*/
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nWorkers = workers.size(), nBikes = bikes.size();
        vector<Distance> vdist(nWorkers* nBikes);
        int k = 0;
        for (int i = 0; i < nWorkers; ++i) {
            for (int j = 0; j < nBikes; ++j) {
                int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                vdist[k++] = {distance,i,j};
            }
        }
        /*
        struct {
            bool operator()(const Distance& a, const Distance& b) const {
                bool ret = a.dist < b.dist;
                if (a.dist == b.dist) {
                    ret = a.iw < b.iw;
                    if (a.iw == b.iw) ret = a.ib < b.ib;
                }
                return ret;
            }
        } dcomp;   */ //working
        auto dcomp = [] (const Distance& a, const Distance& b){
                bool ret = a.dist < b.dist;
                if (a.dist == b.dist) {
                    ret = a.iw < b.iw;
                    if (a.iw == b.iw) ret = a.ib < b.ib;
                }
                return ret;
            }; //working too
        
        sort(vdist.begin(), vdist.end(), dcomp);
        vector<bool> assignedWorker(nWorkers, false);
        vector<bool> assignedBike(nBikes, false);
        vector<int> ans(nWorkers,-1);
        int count = 0;
        for (k  = 0; k < vdist.size(); ++k) {
            if (count == nWorkers) break; //all workers assigned with bike
            Distance d = vdist[k];
            if (!assignedWorker[d.iw] && !assignedBike[d.ib]) {
                assignedWorker[d.iw] = true;
                assignedBike[d.ib] = true;
                ans[d.iw] = d.ib;
                count++;
            }
            
        }
        return ans;
        
    }
private:
    struct Distance {
        int dist, iw, ib;
        /*
        bool operator<(Distance& other) {
            bool ret = dist < other.dist;
            if (dist == other.dist) {
                ret = iw < other.iw;
                if (iw == other.iw) ret = ib < other.ib;
            }
            return ret;
        }*/
    };
};


//lt discuss idea, sort all work - bike distance, then consider each distance in order, track if a worker/bike is assigned or not

//runtime 216ms, faster than 70%, mem less than 100%


