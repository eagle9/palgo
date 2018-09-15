//idea is similar to string permutations ii solution by jz
//speed is Your submission beats 99.80% Submissions!
public class Solution {
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        result.add(convert(nums));
        while ((nums = nextPermutation(nums)) != null) {
            result.add(convert(nums));
        }
        return result;
    }
    private List<Integer> convert(int[] nums) {
        List<Integer> list = new ArrayList<Integer>(nums.length);
        for (int i : nums)  {
            list.add(i);
        }
        return list;
    }
    public int [] nextPermutation(int [] nums) {
        int index = -1;
        for(int i = nums.length -1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }
        if(index == -1){
            return null;
        }
        for(int i = nums.length -1; i > index; i--){
            if(nums[i] > nums[index]){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        reverse(nums,index+1,nums.length-1);
        return nums;

    }
    
    public void reverse(int [] num, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
}
