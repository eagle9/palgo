//adpated from jiadai c++, Your submission beats 74.80% Submissions!
class Solution {
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    public List<List<Integer> > combinationSum2(int [] num, int target) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if (num.length == 0 || target <= 0) {
            return result;
        }
        Arrays.sort(num);
        List<Integer> numbers = new ArrayList<>();
        dfs(num, 0, target, numbers, result);
        return result;
    }
    
    private void dfs(int[] num, int start, int target, List<Integer> numbers,
             List<List<Integer>> result)
    {
        if (target == 0) {
            //result.add(numbers); this won't work, why? only want this copy at this moment
            // the contents at numbers will be changed through out the function call
            result.add(new ArrayList<Integer>(numbers));
            return;
        }

        for (int i = start; i < num.length; ++i) {
            if (num[i] <= target) {
                if (i == start || num[i] != num[i - 1]) {
                    numbers.add(num[i]);
                    dfs(num, i + 1, target - num[i], numbers, result);
                    numbers.remove(numbers.size()-1);
                }
            }
            else {
                break;
            }
        }
    }
};
