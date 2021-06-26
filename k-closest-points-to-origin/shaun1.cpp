//this program is a workout for me to learn how to improve programming efficiency, presentation by huahua
//
//sort with compare object directly
//time nlogn, no extra space
//runtime 260ms, faster than 69%, mem less than 99%
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        struct pCompare{
            bool operator () (vector<int>&a, vector<int>& b) const{
                return a[0]*a[0]+ a[1]*a[1] < b[0]*b[0]+ b[1]*b[1];
            }
        } pCompare1;
        sort(points.begin(), points.end(), pCompare1);
        //sort(points.begin(), points.end(), pCompare());
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }
};

//use pair to store pre-computed distance and index, then sort
//code myself upon hua idea hint
//runtime 252ms, faster than 76%, mem less than 82%
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,int>> vp(points.size());//vector of pair
        //pair of distance and i
        for (int i = 0; i < points.size(); ++i) {
            vp[i] = make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1], i);
        }
        sort(vp.begin(), vp.end());
        vector<vector<int>> res(K);
        for (int i = 0; i < K; ++i) res[i] = points[vp[i].second];
        
        return res;
    }
};

//upon hua's idea to use long to encode distance and index
//also learned the use of static_cast<type> (data), static_cast is keyword
//runtime 228ms, faster than 92%, mem less than 82%
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<long> v(points.size());
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            v[i] = (static_cast<long> (dist) << 32) | i;
        }
        sort(v.begin(), v.end());
        vector<vector<int>> res(K);
        for (int i = 0; i < K; ++i) {
            res[i] = points[ static_cast<int>(v[i])];
        }
        return res;
    }
};

