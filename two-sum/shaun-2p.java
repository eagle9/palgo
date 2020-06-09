/*
4ms, faster than 45%, mem less than 6%
*/
class Solution {
    
    class Pair implements Comparable<Pair>{
        public int value,index;
        public Pair(int v, int i) {
            value =v;
            index =i;
        }
        public int compareTo(Pair other) {
            return Integer.compare(value, other.value);
        }
    }
    public int[] twoSum(int[] nums, int target) {
        Pair [] pairs = new Pair[nums.length];
        for (int i = 0; i < nums.length; i++) {
            pairs[i] = new Pair(nums[i],i);
        }
        Arrays.sort(pairs);
        int left = 0, right = nums.length-1;
        while (left < right) {
            int sum = pairs[left].value + pairs[right].value;
            if ( sum == target) {
                int [] res = {pairs[left].index, pairs[right].index};
                return res;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        int [] res = {};
        return res;
    }
}
