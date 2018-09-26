//adapted from jiadai c++ Your submission beats 95.40% Submissions!
class Solution {
    
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    List<List<Integer>> combinationSum(int []nums, int target) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if (nums.length == 0 || target <= 0) {
            return result;
        }
        Arrays.sort(nums);
        int k = 0; //unique index
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[k]) {
                //found another unique number
                k++;
                nums[k] = nums[i];
            }
            //equal k remain the same
        }
        int [] a = new int[k+1];
        for (int i = 0; i < a.length; i++) {
            a[i] = nums[i];
        }

        ArrayList<Integer> numberlist = new ArrayList<>();
        dfs(a, 0, target, numberlist,result);
        return result;
    }
    
    /*
    @param a: array of numbers that are unique and in ascending order
    @param start: a[start] to add to cd (candidate combination)
    @param target: target for the sum
    @param cd: candidate list of numbers that add to target
    @param res: result list of combinations
    */
    private void dfs(int [] a, int start, int target, List<Integer> cd, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<Integer>(cd));
            return;
        }

        for (int i = start; i < a.length; ++i) {
            if (a[i] <= target) {
                cd.add(a[i]);
                dfs(a, i, target - a[i], cd,res);
                cd.remove(cd.size()-1);
                
            } else {
                break;
            }
        }
    }

};
