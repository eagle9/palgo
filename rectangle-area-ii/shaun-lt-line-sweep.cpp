/*
https://leetcode.com/articles/rectangle-area-ii/
lt Approach #3: Line Sweep
shaun modified and understood
runtime 4ms, faster than 99.77%, mem less than 86%

Intuition
Imagine we pass a horizontal line from bottom to top over the shape. We have some active intervals on this horizontal line, which gets updated twice for each rectangle. In total, there are 2 * N events, and we can update our (up to NN) active horizontal intervals for each update.

Algorithm

For a rectangle like rec = [1,0,3,1], the first update is to add [1, 3] to the active set at y = 0, and the second update is to remove [1, 3] at y = 1. Note that adding and removing respects multiplicity - if we also added [0, 2] at y = 0, then removing [1, 3] at y = 1 will still leave us with [0, 2] active.

This gives us a plan: create these two events for each rectangle, then process all the events in sorted order of y. The issue now is deciding how to process the events add(x1, x2) and remove(x1, x2) such that we are able to query() the total horizontal length of our active intervals.

We can use the fact that our remove(...) operation will always be on an interval that was previously added. Let's store all the (x1, x2) intervals in sorted order. Then, we can query() in linear time using a technique similar to a classic LeetCode problem, Merge Intervals.

*/
enum TYPE {OPEN,CLOSE};
class Solution {
private:
    struct Event {
        int y, x1, x2;
        TYPE type; 
        Event(int y, TYPE type, int x1, int x2): y(y), type(type), x1(x1), x2(x2) {}
        bool operator<(Event other) {
            return y < other.y;
        }
    };
    
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
    
        //int OPEN = 0, CLOSE = 1;
        vector<Event> events;
        
        for (vector<int> rec: rectangles) {
            events.push_back(Event(rec[1], OPEN, rec[0], rec[2]));
            events.push_back(Event(rec[3], CLOSE, rec[0], rec[2]));
        }
        sort(events.begin(), events.end());

        vector<pair<int,int>> active; //active intervals during line sweep
        int cur_y = events[0].y;
        long ans = 0;
        for (auto event: events) {
            int y = event.y, type = event.type, x1 = event.x1, x2 = event.x2;

            // Calculate query, merge intervals
            long query = 0;

            //int cur = -1;
			int cur = INT_MIN;
            for (auto intv: active) {
                //intv.first intv.second contributes to the area???
                cur = max(cur, intv.first); //cur is prev interval's end, if its greater, take cur
                query += max(intv.second - cur, 0); //contribution to width, xs.second > cur to contribute, otherwise overlapping
                cur = max(cur, intv.second);
            }

            ans += query * (y - cur_y);

            if (type == OPEN) { //OPEN add interval to active
                active.emplace_back(x1, x2);
                sort(active.begin(), active.end());
            } else { //CLOSE erase interval from active
                for (int i = 0; i < active.size(); ++i) {
                    if (active[i].first == x1 && active[i].second == x2) {
                        active.erase(active.begin()+i);
                        break;
                    }
                }
            }

            cur_y = y;
        }

        ans %= 1000000007;
        return (int) ans;
    }
};
