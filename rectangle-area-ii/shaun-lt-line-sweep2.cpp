
/*
Complexity Analysis
Time Complexity: O(N^2 \log N), where N is the number of rectangles.
Space Complexity: O(N)

cutting: lt line sweep from y=0 to highest
  each rectangle contributes 2 event, open an interval x1,x2 at y1, close an interval x1,x2 at y2
  get all the events, sort them by y
  then go over the sorted events
  use active intevals to calculate width at y, track cur_y, accumulate to area
  if open event, add x1,x2 to active interval list
  if close event, remove x1,x2 from active interval list
c++ from lt java code idea
runtime 44ms, faster than 7%, mem less than 25%


Approach #3: Line Sweep
Intuition

Imagine we pass a horizontal line from bottom to top over the shape. We have some active intervals on this horizontal line, which gets updated twice for each rectangle. In total, there are 2 * N2∗N events, and we can update our (up to NN) active horizontal intervals for each update.

Algorithm

For a rectangle like rec = [1,0,3,1], the first update is to add [1, 3] to the active set at y = 0, and the second update is to remove [1, 3] at y = 1. Note that adding and removing respects multiplicity - if we also added [0, 2] at y = 0, then removing [1, 3] at y = 1 will still leave us with [0, 2] active.

This gives us a plan: create these two events for each rectangle, then process all the events in sorted order of y. The issue now is deciding how to process the events add(x1, x2) and remove(x1, x2) such that we are able to query() the total horizontal length of our active intervals.

We can use the fact that our remove(...) operation will always be on an interval that was previously added. Let's store all the (x1, x2) intervals in sorted order. Then, we can query() in linear time using a technique similar to a classic LeetCode problem, Merge Intervals.
runtime 39ms, faster than 48%, mem less than 33%
*/
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int OPEN = 0, CLOSE = 1;
        vector<vector<int>> events(rectangles.size() * 2, vector<int>(4));
        int t = 0;
        //each rectangle contributes 2 events
        // y, open, x1, x2 -- open an interval x1,x2 at y
        // y, close,x1, x2 -- close an interval x1,x2 at y
        for (auto rec: rectangles) {
            events[t++] = {rec[1], OPEN, rec[0], rec[2]};
            events[t++] = {rec[3], CLOSE, rec[0], rec[2]};
        }

        //Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        //sort events by y, smaller in front
        sort(events.begin(), events.end(), [](vector<int>a, vector<int>b)-> bool {  return a[0] <b[0];});

        vector<vector<int>> active; //down know the size, so use List
        int cur_y = events[0][0];
        long area = 0;
        
        //go over event y from 0 to the largest
        for (auto event: events) {
            int y = event[0], type = event[1], x1 = event[2], x2 = event[3];

            // accumulated width covered by active intervals
            long width = 0; 
            int cur = -1;
            for (auto xs: active) {
                int start = xs[0], end = xs[1];
                cur = max(cur, start);
                width += max(end - cur, 0);
                cur = max(cur, end);
            }
            area += width * (y - cur_y);

            
            if (type == OPEN) {
                active.push_back({x1, x2});
                //active is a List<int<>>
                sort(active.begin(), active.end(), [](vector<int>a, vector<int>b) -> bool {return a[0] < b[0];});
            } else { //type == CLOSE
                //remove interval x1,x2 from active list
                for (int i = 0; i < active.size(); ++i) {
                    if (active[i][0] == x1 && active[i][1] == x2) {
                        active.erase(active.begin() + i);
                        break;
                    }
                }
            }

            cur_y = y;
        }

        area %= 1000000000+7;
        return (int) area;
    }
};
