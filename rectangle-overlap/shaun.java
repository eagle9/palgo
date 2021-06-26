class Solution1 {
    //fuxue idea, beats 18%
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        //overlap along x axis
        int dx = Math.min(rec1[2], rec2[2]) - Math.max(rec1[0], rec2[0]);
        //overalp along y axis
        int dy = Math.min(rec1[3], rec2[3]) - Math.max(rec1[1], rec2[1]);
        
        return dx>0 && dy > 0;
    }
}

class Solution {
    //jz idea, beats 18%, draw a picture you will understand
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int left1x = rec1[0];
        int left1y = rec1[1];
        int right1x = rec1[2];
        int right1y = rec1[3];
        
        int left2x = rec2[0];
        int left2y = rec2[1];
        int right2x = rec2[2];
        int right2y = rec2[3];
        
        //not overlap
        if (right1x <= left2x || right2x <= left1x) return false;
        if (right1y <= left2y || right2y <= left1y) return false;
        return true;
    }
}
