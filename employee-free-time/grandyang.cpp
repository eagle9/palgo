/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
Runtime: 76 ms, faster than 97.62% of C++ online submissions for Employee Free Time.
Memory Usage: 21.1 MB, less than 100.00% of C++ online submissions for Employee Free Time.
grandyang idea1

*/
class Solution1 {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> res, v;
        for (auto a : schedule) {
            v.insert(v.end(), a.begin(), a.end());
        }
        sort(v.begin(), v.end(), [](Interval &a, Interval &b) {return a.start < b.start;});
        Interval t = v[0];
        for (Interval i : v) {
            if (t.end < i.start) {
                res.push_back(Interval(t.end, i.start));
                t = i;
            } else {
                t = (t.end < i.end) ? i : t;
            }
        }
        return res;
    }
};
/*
Runtime: 84 ms, faster than 69.05% of C++ online submissions for Employee Free Time.
Memory Usage: 22.2 MB, less than 100.00% of C++ online submissions for Employee Free Time.
grandyang idea using treemap
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> res;
        map<int, int> m;
        int cnt = 0;
        for (auto employee : schedule) {
            for (Interval i : employee) {
                ++m[i.start];
                --m[i.end];
            }
        }
        for (auto a : m) {
            cnt += a.second;
            if (!cnt) res.push_back(Interval(a.first, 0));
            if (cnt && !res.empty() && !res.back().end) res.back().end = a.first;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};
