class Solution {
    /**

     time : O(n^2)
     space : O(n)
     space : ON^2???
     Runtime: 81 ms, faster than 86.23% of Java online submissions for 4Sum II.
Memory Usage: 60.2 MB, less than 19.28% of Java online submissions for 4Sum II.
     
     * @param A
     * @param B
     * @param C
     * @param D
     * @return
     */
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int a : A) {
            for (int b : B) {
                int sum = a + b;
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
        }
        for (int c : C) {
            for (int d : D) {
                int sum = -c - d;
                res += map.getOrDefault(sum, 0);
            }
        }
        return res;
    }
}

