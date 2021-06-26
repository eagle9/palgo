class Solution {
    //beats 15%, feixuemingzhu idea, shaun java code
    public int maxDistToClosest(int[] seats) {
        int index = -200000;
        int [] ans = new int[seats.length];
        
        //move from left to right
        //now ans[i] stores distance from left to right for each i seat taken
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1) {
                index = i;
            }else { //empty seat
                ans[i] = Math.abs(i - index);
            }
        }
        //move from right to left
        //update ans i with distance from right to left, take min
        //record max of such ans i
        index = -20000;
        int max = -1;
        for (int i = seats.length-1; i >= 0; i--){
            if (seats[i] == 1) {
                index = i;
            }else {
                ans[i] = Math.min(ans[i], Math.abs(i - index));
                max = Math.max(ans[i], max);
            }
        }
        
        return max;
    }
}


/*
class Solution(object):
    #https://blog.csdn.net/fuxuemingzhu/article/details/80643250
    #beats 21%
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        index = -200000
        _len = len(seats)
        ans = [0] * _len
        for i in range(_len):
            if seats[i] == 1:
                index = i
            else:
                ans[i] = abs(i - index)
        index = -200000
        for i in range(_len - 1, -1, -1):
            if seats[i] == 1:
                index = i
            else:
                ans[i] = min(abs(i - index), ans[i])
        return max(ans)

*/
