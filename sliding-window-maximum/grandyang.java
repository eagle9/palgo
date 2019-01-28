//grandyang idea with deque, deque only store the index of element whose value is >= current number

//runtime 11ms, faster than 83%
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || nums.length < k) return new int[] {};
        
        int [] res = new int[nums.length - k + 1];
        //List<Integer> res = new ArrayList<>();
        int idx = 0;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            if (!q.isEmpty() && q.getFirst() == i - k) q.pollFirst();
            //remove q elements whose value is < current number
            while (!q.isEmpty() && nums[q.peekLast()] < nums[i]) q.pollLast();
            //now q only store element index whose value >= nums[i]
            q.offerLast(i);
            if (i >= k - 1) res[idx++] = nums[q.peekFirst()];
        }
        /*
        int [] a = new int[res.size()];
        for (int i = 0; i < a.length; i++) {
            a[i] = res.get(i);
        }
        return a;
        */
        return res;
    }
}
