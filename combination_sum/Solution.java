//adapted from jiadai c++ Your submission beats 95.40% Submissions!
class Solution {
    
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    List<List<Integer>> combinationSum(int []candidates, int target) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if (candidates.length == 0 || target <= 0) {
            return result;
        }
        Arrays.sort(candidates);
        int prev = 0; //prev unique index
        for (int i = 1; i < candidates.length; ++i) {
            if (candidates[i] != candidates[prev]) {
                candidates[++prev] = candidates[i];
            }
        }
        int [] c = new int[prev+1];
        for (int i = 0; i < c.length; i++) {
            c[i] = candidates[i];
        }

        ArrayList<Integer> numberlist = new ArrayList<>();
        dfs(c, 0, target, numberlist,result);
        return result;
    }
    
    private void dfs(int [] candidates, int start, int target, List<Integer> numberlist, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<Integer>(numberlist));
            return;
        }

        for (int i = start; i < candidates.length; ++i) {
            if (candidates[i] <= target) {
                numberlist.add(candidates[i]);
                dfs(candidates, i, target - candidates[i], numberlist,result);
                numberlist.remove(numberlist.size()-1);
                
            } else {
                break;
            }
        }
    }

};
