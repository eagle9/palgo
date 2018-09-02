//adapted from jiadai c++, Your submission beats 83.20% Submissions!
class Solution {
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    public List<List<Integer>> kSumII(int[] A, int k, int target) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> numbers = new ArrayList<>();
        Arrays.sort(A);
        dfs(A, 0, k, 0, target, numbers, result);
        return result;
    }

    private void dfs(int[] A, int start, int k, int sum, int target, List<Integer> numbers, List<List<Integer>> result) {
        if (k == 0 || start == A.length) {
            if (sum == target && k == 0) {
                result.add(new ArrayList<Integer>(numbers));
            }
            return;
        }

        for (int i = start; i < A.length && sum + A[i] <= target; ++i) {
            numbers.add(A[i]);
            dfs(A, i + 1, k - 1, sum + A[i], target, numbers, result);
            numbers.remove(numbers.size()-1);
        }
    }
};
