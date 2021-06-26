/*
       x2, y2

x1, y1

overlap
    [y1,     y2]
 [y3, y4]  [y3, y4]
 
 shaun own idea with interval overlap checking,  wrong answer
 accepted after fixing two bugs
 use min(start1, start2) and max(end1, end2) to check overlap, cleaner
 runtime 0ms, faster than 100%, mem less than 99.60%
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return helper(y1,y2, y3, y4) && helper(x1, x2, x3, x4);
    }
private:
    //check if two intervals y1<y2  and y3<y4 overlap 
    //y1   <   y2 
    //     y3   <   y4 
    //y3   < . y4 
    //     y1  < .  y2
    bool helper(int y1, int y2, int y3, int y4) {
        //return (y4 < y1 || y3 < y2 );   bug
        //return  (y1< y3 && y3 < y2) || (y1 < y4 && y4 < y2);  bug
        int start = max(y1, y3), end = min(y2, y4);
        //both started and last for an overalapped time
        return start < end;
    }
};
