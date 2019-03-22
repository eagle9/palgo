//shaun own idea and first try, forgot init to INT_MAX, corrected it and accepted
//runtime 8ms, faster than 100%
class Solution1 {
public:
    int minCost(vector<vector<int>>& costs) {
        int nh = costs.size(); //number of houses
        if (nh == 0) return 0; //no houses
        if (costs[0].size() != 3) return 0; //input data error
        //first submission forgot init to INT_MAX
        vector<int> r(nh,INT_MAX), g(nh,INT_MAX),b(nh,INT_MAX); //min cost using color at house i
        r[0] = costs[0][0];
        g[0] = costs[0][1];
        b[0] = costs[0][2];
        for (int i = 1; i < nh; ++i) {
        	r[i] = min(r[i],costs[i][0] + min(g[i-1],b[i-1]));
        	g[i] = min(g[i],costs[i][1] + min(r[i-1],b[i-1]));
        	b[i] = min(b[i],costs[i][2] + min(r[i-1],g[i-1]));
        }

        return min(min(r[nh-1], g[nh-1]), b[nh-1]);

    }
};

//optimize and reduce space usage and dp array dimension
//runtime 8ms, faster than 100%
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int nh = costs.size(); //number of houses
        if (nh == 0) return 0; //no houses
        if (costs[0].size() != 3) return 0; //input data error
        //first submission forgot init to INT_MAX
        int r = costs[0][0];
        int g = costs[0][1];
        int b = costs[0][2];
        for (int i = 1; i < nh; ++i) {
            int r2 = costs[i][0] + min(g,b);
        	int g2 = costs[i][1] + min(r,b);
        	int b2 = costs[i][2] + min(r,g);
            r = r2; g = g2; b = b2;
        }

        return min(min(r,g), b);

    }
};

/*
idea:
         r  g  b
Input: [[17,2,17]   h0
        [16,16,5],  h1
        [14,3,19]]  h2
key point:   no 2 adj houses same color, min cost to paint all
      r             b   g    <--min cost of using color to hi    ans  = min
h0    17            2   17                                        2
h1    16+min(2,7)   16+min(17,17)    5 + min(2,17)                7
h2    14+min(33,7)  3+min(18,7)      19+min(18,33)                10
*/
