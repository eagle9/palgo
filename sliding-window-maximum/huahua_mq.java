//huahua idea,monotonic queue with sliding window, shaun java code, 
//runtime 9ms, faster than 92%
class MonotonicQueue {
    //when push e, remove all elements that < e
    public void push(int e) {
        while(!dq.isEmpty() && dq.peekLast() < e) dq.pollLast();   //pop smaller elements before push
        dq.offerLast(e);
    } 
  
    public void pop() {
        dq.pollFirst();
    }
  
    public int max() { return dq.peekFirst(); }
    
    private Deque<Integer> dq = new ArrayDeque<>();
};
 
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0|| nums.length < k) return new int[]{};
        
        MonotonicQueue q = new MonotonicQueue();
        int [] res = new int[nums.length-k+1];
        int idx = 0;
        for (int right = 0; right < nums.length; right++) {
            q.push(nums[right]);
            //  left   ---    right
            //  right-k+1 ---  right 
            //enough number in the window
			int left = right - k + 1;
            if (left >= 0) {
                res[idx++] = q.max();
                if (nums[left] == q.max()) q.pop(); //why?   right add, left remove 
            }
        }
        return res;
    }
}
/*
Output: [3,3,5,5,6,7] 
window position                Max  n[left]  q
---------------               -----  ---   ----
 [1] 3 -1  -3  5  3  6  7                 [1]      push 1 
 [1 3] -1  -3  5  3  6  7                 [3]      push 3 
[1  3  -1] -3  5  3  6  7       3    1    [3,-1]    push -1, i-k+1>=0 now
 1 [3  -1  -3] 5  3  6  7       3    3    [3,-1,-3] --> [-1,-3]    push -3,
 1  3 [-1  -3  5] 3  6  7       5    -1	  [5]       push 5 
 1  3  -1 [-3  5  3] 6  7       5    -3   [5,3]     push 3  
 1  3  -1  -3 [5  3  6] 7       6    5    [6]       push 6
 1  3  -1  -3  5 [3  6  7]      7    3    [7]       push 7


input [1 -1],   k =1
output: [1 -1]
                 max   n[left]     q
[1] -1           1      1          [1]
1   [-1]         -1                [1,-1]


*/

