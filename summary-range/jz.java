//jz Qstudent min代表range小的数，max代表大的数
//如果min跟mx一样，说明只有一个数，就不需要->
//beats 100%
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();
        if (nums == null ||nums.length == 0) {
            return result;
        }
        int min = nums[0]; 
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            
            //i-1   to i not continuous integer, have to summarize range
            if (nums[i] - 1 != nums[i - 1]) {
                result.add((min == max) ? (min + "") : (min + "->" + max));
                
                //update min
                min = nums[i];
            } 
            //if i-1 to i continuous, no update min
            max = nums[i];
        }
        // add the last range
        result.add((min == max) ? (min + "") : (min + "->" + max));
        return result;
    }
}
