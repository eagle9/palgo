// Non Recursion
//use binary way to enumerate subsets, rely on math
//Your submission beats 90.60% Submissions!

class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        int n = nums.length;
        Arrays.sort(nums);
        
        // 1 << n is 2^n
        // each subset equals to an binary integer between 0 .. 2^n - 1
        // 0 -> 000 -> []
        // 1 -> 001 -> [1]
        // 2 -> 010 -> [2]
        // ..
        // 7 -> 111 -> [1,2,3]
        int N = 1 << n;
        for (int i = 0; i < N; i++) {
            List<Integer> subset = new ArrayList<Integer>();
            for (int j = 0; j < n; j++) {
                // check whether the jth digit in i's binary representation is 1
                int mask = 1 << j; //jth digit from right
                if ((i & mask) != 0) {  //i's jth digit ==1 , choose jth number in nums
                    subset.add(nums[j]);
                }
            }
            result.add(subset);
        }
        return result;
    }
}
