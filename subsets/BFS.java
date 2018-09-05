//ling huchong, use bfs, find all subsets level by level
//Your submission beats 47.20% Submissions!
public class Solution {
    
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        // List vs ArrayList （google）
        List<List<Integer>> results = new LinkedList<>();
        
        if (nums == null) {
            return results; // empty list
        }
        
        Arrays.sort(nums);
        
        // BFS
        Queue<List<Integer>> queue = new LinkedList<>();
        queue.offer(new LinkedList<Integer>());
        
        while (!queue.isEmpty()) {
            List<Integer> subset = queue.poll();
            results.add(subset);
            
            for (int i = 0; i < nums.length; i++) {
                if (subset.size() == 0 || subset.get(subset.size() - 1) < nums[i]) {
                    List<Integer> nextSubset = new LinkedList<Integer>(subset);
                    nextSubset.add(nums[i]);
                    queue.offer(nextSubset);
                }
            }
        }
        
        return results;
    }
}
