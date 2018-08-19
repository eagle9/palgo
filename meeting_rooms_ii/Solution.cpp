/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//Your submission beats 100.00% Submissions!
//jiadai
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        vector<pair<int, int>> times;
        for (Interval i : intervals) {
            times.emplace_back(i.start, 1);
            times.emplace_back(i.end, 0);
        }
        sort(times.begin(), times.end());
        int count = 0, maxCount = 0;
        for (auto t : times) {
            if (t.second) { //t.second access pair's second element
                ++count;
                maxCount = max(maxCount, count);
            }
            else {
                --count;
            }
        }
        return maxCount;
    }
};
