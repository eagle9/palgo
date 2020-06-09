/*
lt idea, no need to sort keys, makes sense, only need to worry about key+1 in or not
good idea, unordered map is faster
Runtime: 16 ms, faster than 82.79% of Java online submissions for Longest Harmonious Subsequence.
Memory Usage: 40.7 MB, less than 94.74% of Java online submissions for Longest Harmonious Subsequence.

*/
public class Solution {
    public int findLHS(int[] nums) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int res = 0;
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int key: map.keySet()) {
            if (map.containsKey(key + 1))
                res = Math.max(res, map.get(key) + map.get(key + 1));
        }
        return res;
    }
}
