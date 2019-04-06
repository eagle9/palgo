//grandyang binary search of value space, shaun understood
//runtime 40ms, faster than 71%, mem less than 100%
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;//station position range
        //left and right are double, not integer, so keep taking mid will bring them closer and closer
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (helper(stations, K, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
    //candidate mid bigger? 
    bool helper(vector<int>& stations, int K, double mid) {
        int cnt = 0, n = stations.size();
        for (int i = 0; i < n - 1; ++i) {
            //add station with distance = mid
            cnt += (stations[i + 1] - stations[i]) /  mid;
        }
        //mid works if enough(not over K)
        return cnt <= K;
    }
};
