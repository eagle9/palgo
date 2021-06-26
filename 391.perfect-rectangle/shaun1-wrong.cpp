class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (hasOverlap(rectangles)) return false;
            
        int total_area = 0;
        int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax=INT_MIN;
        int n = rectangles.size();
        vector<Interval> xi;
        vector<Interval> yi;
        for (int i = 0; i < n; ++i) {
            vector<int> v = rectangles[i];
            xi.push_back(Interval(v[0], v[2]));
            yi.push_back(Interval(v[1], v[3]));
            xmin = min(xmin,v[0]);
            xmax = max(xmax,v[2]);
            ymin = min(ymin,v[1]);
            ymax = max(ymax,v[3]);
            total_area += (v[2]-v[0]) * (v[3]-v[1]);
        }
        if (hasOverlap(xi) || hasOverlap(yi)) return false;
        //no overlap now
        return total_area == (xmax-xmin)*(ymax-ymin);
    }
private:
    struct Interval {
        int start;
        int end;
        Interval(int start, int end): start(start), end(end){
            
        }
        bool operator<(Interval& other) const {
            return start < other.start;
        }
    };
    bool hasOverlap(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                
            }
        }
    }

};
