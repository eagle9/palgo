//Your submission beats 79.20% Submissions!
//jz
public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    public List<Integer> medianSlidingWindow(int[] nums, int k) {
        // write your code here
        if (nums == null || nums.length == 0) {
            return new ArrayList<Integer>();
        }
        List<Integer> res = new ArrayList<>();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer> () {
                public int compare(Integer x, Integer y) {
                    return y - x;
                }
            });
        
        int curMedian;
        if (k > 1) {
            maxHeap.add(nums[0]);
            for (int i = 1; i < k - 1; i++) {
                int x = maxHeap.peek();
                if (nums[i] <= x) {
                    maxHeap.add(nums[i]);
                } else {
                    minHeap.add(nums[i]);
                }
            }
            curMedian = maxHeap.peek();
        } else {
            curMedian = 0;
        }
        
        for (int i = k - 1; i < nums.length; i++) {
            if (nums[i] <= curMedian) {
                maxHeap.add(nums[i]);
            } else {
                minHeap.add(nums[i]);
            }
            while (maxHeap.size() > minHeap.size()+1) {
                minHeap.add(maxHeap.poll());
            }
            while (maxHeap.size() < minHeap.size()) {
                maxHeap.add(minHeap.poll());
            }
            curMedian = maxHeap.peek();
            res.add(curMedian);
            if (nums[i - k + 1] <= curMedian) {
                maxHeap.remove(nums[i - k + 1]);
            } else {
                minHeap.remove(nums[i - k + 1]);
            }
        }
        
        return res;
    }
}
