/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    class Time  {
        int time;
        boolean flag;
        int id;
        public Time(int time, boolean flag, int id) {
            this.time = time;
            this.flag = flag;
            this.id = id;
        }
        
    }
    //beats 40%, jz idea and shaun coded, lintcode accepted but leetcode not accept. leetcode has more test cases. decided to use leetcode mainly
    public int minMeetingRooms(Interval[] intervals) {
        Arrays.sort(intervals, new Comparator<Interval>(){
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        int n = intervals.length;
        List<Time> tlist = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tlist.add(new Time(intervals[i].start,true,i));
            tlist.add(new Time(intervals[i].end,false,i));
        }
        //[13,15], [1,13] test case that failed jz idea
        Collections.sort(tlist, new Comparator<Time>(){
            public int compare(Time t1, Time t2) {
                if (t1.time == t2.time) {
                    return t1.id - t2.id;
                } else
                    return t1.time - t2.time;
            }
        });
        int max = 0;
        int count = 0;
        
        for (Time t: tlist) {
            //start
            
            if (t.flag) {
                count++;
                
            }else {
                count--;
            }
            max = Math.max(count,max);
        }
        return max;
    }
}
