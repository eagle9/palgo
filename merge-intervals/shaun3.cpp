//shaun 3rd round, remembered idea
//runtime 16ms, faster than 76%, mem less than 14%

struct {
    //bool operator()(Interval a, Interval b){  //okay too
    bool operator()(Interval &a, Interval& b) const {
        return a.start < b.start;  //smaller i.start in front
    }    
} iCompare;

struct tCompare{
    //bool operator()(Interval a, Interval b){  //okay too
    bool operator()(Interval &a, Interval& b) const {
        return a.start < b.start;  //smaller i.start in front
    }    
} ;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; //don't miss this corner case
        
        int n = intervals.size();
        vector<Interval> intervals2(n);
        for (int i = 0; i < n; ++i) intervals2[i] = Interval(intervals[i][0],intervals[i][1]);
        
        vector<Interval> res;
        //sort(intervals2.begin(), intervals2.end(), iCompare);
        sort(intervals2.begin(), intervals2.end(), tCompare());
        res.push_back(intervals2[0]);
        
        for (int i = 1; i < intervals2.size(); ++i){
            
            //prev.start prev.end
            //                     i.start i.end
            //no overlap, no need to merge
            if (res.back().end < intervals2[i].start) {
                res.push_back(intervals2[i]);
            } 
            //prev.start   prev.end
            //        i.start i.end
            //overlap with prev, update prev
            if (intervals2[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals2[i].end);
            }
            
        }
        vector<vector<int>> res2(res.size());
        for (int i = 0; i < res.size(); ++i) {
            res2[i] = {res[i].start, res[i].end};
        }
        return res2;
    }
};

