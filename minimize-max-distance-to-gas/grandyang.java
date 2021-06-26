/*
Runtime: 19 ms, faster than 90.61% of Java online submissions for Minimize Max Distance to Gas Station.
Memory Usage: 40.4 MB, less than 0.64% of Java online submissions for Minimize Max Distance to Gas Station.
grandyang binary search, same as lt
*/

class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (helper(stations, K, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
    boolean helper(int [] stations, int K, double dist) {
        //cnt is the sum the multiples:  distance from i to i+1 is how many times of dist?
        int cnt = 0, n = stations.length;
        for (int i = 0; i <= n - 2; ++i) {
            cnt += (stations[i + 1] - stations[i]) / dist;
        }
        return cnt <= K;
    }
}
