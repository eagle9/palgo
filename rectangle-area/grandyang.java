/* grandyang idea2
不算一道很难的题，但是我还是花了很久才做出来，刚开始我尝试找出所以有重叠的情况，发现有很多种情况，很麻烦。后来换了一种思路，尝试先找出所有的不相交的情况，只有四种，一个矩形在另一个的上下左右四个位置不重叠，这四种情况下返回两个矩形面积之和。其他所有情况下两个矩形是有交集的，这时候我们只要算出长和宽，即可求出交集区域的大小，然后从两个巨型面积之和中减去交集面积就是最终答案。求交集区域的长和宽也不难，由于交集都是在中间，所以横边的左端点是两个矩形左顶点横坐标的较大值，右端点是两个矩形右顶点的较小值，同理，竖边的下端点是两个矩形下顶点纵坐标的较大值，上端点是两个矩形上顶点纵坐标的较小值。
beats 32%
*/
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int total = (C-A) * (D-B) + (G-E)*(H-F);
        
        //AC   EG
        //BD   FH
        //this is the correct condition to test overlap
        if (E >= C || F >= D || B >= H || A >= G) return total;
        
        //now there is overlap
        int dx = Math.min(C,G) - Math.max(A,E);
        int dy = Math.min(D,H) - Math.max(B,F);
        
        //if there is overlap
        //if (dx > 0 && dy > 0) { //does not work
        //if ((dx >0 && dy>0) || (dx < 0 && dy < 0)) {
        //you can not use dx and dy to test overlap, once there is overlap, if you use it
        return total - dx* dy;
        
    }
}
