//runtime 0ms, faster than 100%, mem less than 65%
//shaun own idea, but forgot after 6 month, picked up back quickly
//cutting: the most cost of painting to house i, 3 cases, 3 arrays to store them
//check shaun-own-dp.cpp idea
class Solution {
    public int minCost(int[][] costs) {
        int nh = costs.length; //number of houses
        if (nh == 0) return 0; //no houses
        if (costs[0].length != 3) return 0; //input data error
        //first submission forgot init to INT_MAX
        int r = costs[0][0];
        int g = costs[0][1];
        int b = costs[0][2];
        for (int i = 1; i < nh; ++i) {
            int r2 = costs[i][0] + Math.min(g,b);
            int g2 = costs[i][1] + Math.min(r,b);
            int b2 = costs[i][2] + Math.min(r,g);
            r = r2; g = g2; b = b2;
        }

        return Math.min(Math.min(r,g), b);
    }
}
