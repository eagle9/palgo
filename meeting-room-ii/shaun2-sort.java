class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        //vector<pair<int,int>> t; //pair time and 0/1 markers, 0 for end time, 1 for start time
        List<int[]> t = new LinkedList<>();
        //vector<pair<int,int>> t(2*n); //bug 2 -- t(2n), push_back will append at 2n
        for (int i = 0; i < n; ++i) {
            int start = intervals[i][0], end = intervals[i][1];
            //t.push_back(make_pair(start,1));  //pair start with 1 mark, bug 1-- pair start with 0
            
            t.add(new int[] {start,1});
            //t.push_back(make_pair(end,0));  //pair end with 0 mark, end time will be in front if start tie. end meeting first
            t.add(new int[] {end,0});
        }
        //sort(t.begin(), t.end());
        Collections.sort(t, (a,b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        int rooms = 0, ans = 0;
        for (int[] p: t) {
            //cout << p.first << endl;
            if (p[1] == 1) rooms++;
            ans = Math.max(ans, rooms);
            if (p[1] == 0) rooms--;
        }
        return ans;

    }
}
