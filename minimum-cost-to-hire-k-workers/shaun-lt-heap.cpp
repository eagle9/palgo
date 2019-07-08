struct Worker {
    double ratio;
    double quality;
    Worker() {}; //bug 1, needed if vector<Worker> workers(n) called
    Worker(double ratio, double quality): ratio(ratio), quality(quality) {}
};
//runtime 40ms, faster than 99%, mem less than 82%
//using struct Worker
//accepted with two bug fixes
//shaun from java code
//cutting, sort workers in the order of ratio = w/q
//then iterate workers in the order of ratio
//push quality into maxheap, and keep qsum in the heap
//if heap size > k, pop the max quality, 
//if heap size ==k, ans = min(ans, qsum * current worker's ratio)
// current worker's ratio is greatest so far
//i know the procedures, but not 100% clear about its correctness
// basically, satisfying workers' wage expection, then minimize the cost
//lt heap idea: For each worker in order of ratio, we know all currently considered workers have lower ratio. (This worker will be the 'captain', as described in Approach #1.) We calculate the candidate answer as this ratio times the sum of the smallest K workers in quality.
class Solution1 {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        //vector<pair<double,double>> workers(n);
        vector<Worker> workers(n);
        for (int i = 0; i < n; ++i) {
            //workers[i] = {(double)wage[i]/quality[i], (double)quality[i]};
            workers[i] = Worker((double)wage[i]/quality[i], (double)quality[i]);
        }
        struct {
            bool operator() (Worker& a, Worker& b) const {
                return a.ratio < b.ratio;
            }
        } wcomp;
        sort(workers.begin(), workers.end(), wcomp);
        
        double res = INT_MAX, qsum = 0;
        priority_queue<double> maxheap; //max heap to store quality
        for (auto worker: workers) {
            qsum += worker.quality;
            maxheap.push(worker.quality);
            if (maxheap.size() > K) {
                qsum -= maxheap.top();
                maxheap.pop();
            }
            if (maxheap.size() == K) {
                res = min(res, qsum * worker.ratio); //bug 2 qsum* ratio, not qsum * quality
            }
        }
        return res;
    }
};

//use pair<double,double>
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double,double>> workers(n);
        for (int i = 0; i < n; ++i) {
            workers[i] = {(double)wage[i]/quality[i], (double)quality[i]};
            
        }
        
        sort(workers.begin(), workers.end());
        
        double res = INT_MAX, qsum = 0;
        priority_queue<double> maxheap; //max heap to store quality
        for (auto worker: workers) {
            qsum += worker.second;
            maxheap.push(worker.second);
            if (maxheap.size() > K) {
                qsum -= maxheap.top();
                maxheap.pop();
            }
            if (maxheap.size() == K) {
                res = min(res, qsum * worker.first);
            }
        }
        return res;
    }
};

