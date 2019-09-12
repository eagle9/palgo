i/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*
runtime 12ms, faster than 87%, mem less than 64%
grandyang idea
cutting: for each pair of points i and j, check how many points are on line ij
   for line ij, 
shaun came up with the similar idea,   but missed two key dealings:
1)duplicate points
2)use gcd to represent line slope to avoid floating point
*/



class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1; //count of points that are duplicates of point i
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate; continue;
                } 
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                /*
                As soon as you access the map with the [] operator, if the key doesn't exist it gets added. The default initializer of the int type gets invoked - so it will get a value of 0*/
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);
            //for pointi, m stores slope and line ij count whose slope is the slope 
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
                //res is the max points on a line for all j, given i
            }
        }
        return res;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
