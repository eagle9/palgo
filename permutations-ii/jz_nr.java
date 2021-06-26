//jz no recursion, using next permutation
//Your submission beats 67.20% Submissions!
public class Solution {
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    public List<List<Integer>> permuteUnique(int[] nums) {
        // write your code here
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null) {
            return results;
        }
        
        Arrays.sort(nums);
        
        getAllPermutation(results, nums);
        return results;
    }
    
    private void getAllPermutation(List<List<Integer>> results,
                                   int[] nums) {
        
        results.add(getList(nums));
        
        while (nextPermutation(nums)) {
            results.add(getList(nums));
        }
    }
    
    private boolean nextPermutation(int[] nums) {
        int i = 0;
        for (i = nums.length - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                break;
            }
        }
        
        if (i < 1) {
            return false;
        }
        
        int j = 0;
        for (j = nums.length - 1; j > i - 1; j--) {
            if (nums[j] > nums[i - 1]) {
                swap(i - 1, j, nums);
                break;
            }
        }
        
        reverseAll(i, nums);
        
        return true;
    }
    
    private void swap(int i, int j, int[] nums) {
        if (i == j) return;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    private void reverseAll(int start, int[] nums) {
        for (int i = start, j = nums.length - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
    private List<Integer> getList(int[] nums) {
        List<Integer> list = new ArrayList<>(nums.length);
        for (int val : nums) {
            list.add(val);
        }
        return list;
    }
};
