//huahua idea, shaun java code, 
//runtime 9ms, faster than 92%
class MonotonicQueue {
    //when push e, remove all elements that < e
    public void push(int e) {
        while(!dq.isEmpty() && dq.peekLast() < e) dq.pollLast();
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
        for (int i = 0; i < nums.length; i++) {
            q.push(nums[i]);
            //  left   --- right
            //  i-k+1 ---   i
            //enough number in the window
            if (i - k + 1 >= 0) {
                res[idx++] = q.max();
                if (nums[i - k + 1] == q.max()) q.pop();
            }
        }
        return res;
    }
}

