//shaun intuition with sort of timestamps
//accepted after fixing 2 bugs
//runtime 12ms, faster than 99.50%, mem less than 13%
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> t; //pair time and 0/1 markers, 0 for end time, 1 for start time
        //vector<pair<int,int>> t(2*n); //bug 2 -- t(2n), push_back will append at 2n
        for (int i = 0; i < n; ++i) {
            int start = intervals[i][0], end = intervals[i][1];
            t.push_back(make_pair(start,1));  //pair start with 1 mark, bug 1-- pair start with 0
            t.push_back(make_pair(end,0));  //pair end with 0 mark, end time will be in front if start tie. end meeting first
        }
        sort(t.begin(), t.end());
        int rooms = 0, ans = 0;
        for (auto p: t) {
            //cout << p.first << endl;
            if (p.second == 1) rooms++;
            ans = max(ans, rooms);
            if (p.second == 0) rooms--;
        }
        return ans;
    }
};
