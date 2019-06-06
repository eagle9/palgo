//grandyang idea, cutting angle, go through intervals, before newI, overlapping, after newI
//shaun understand
//runtime 16ms, faster than 80%, mem less than 5%
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int pos = 0; //position of new interval to insert
        
        for (vector<int> ii: intervals) {
            // before newI.start
            if (ii[1] < newInterval[0]) {
                res.push_back(ii);
                pos++;
            }else if (newInterval[1] < ii[0]) { //after newI.end
                res.push_back(ii);
            //overlapping, update the newInterval
            }else {
                newInterval[0] = min(newInterval[0], ii[0]);
                newInterval[1] = max(newInterval[1], ii[1]);
            }
        }
        res.insert(res.begin()+pos, newInterval);
        return res;
    }
};
