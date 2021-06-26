//shaun own idea, accepted after fixing two bugs
//find overlap
//runtime 12ms, faster than 99.39%, mem less than 23%
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true; //bug 1, have to add this line
        
        int n = intervals.size();
        vector<pair<int,int>> vp(n);
        for (int i = 0; i < n; ++i) {
            vp[i] = make_pair(intervals[i][0], intervals[i][1]);
        }
        sort(vp.begin(), vp.end());
        pair<int,int> prev = vp[0];
        for (int i = 1; i < n; ++i) {
            //      vpi.first vpi.second
            //prev.first  prev.second
            //if overlap
            if (vp[i].first < prev.second) return false;
            prev = vp[i]; //bug 2, forgot to update prev
        }
        //no overlap at all
        return true;
    }
};
