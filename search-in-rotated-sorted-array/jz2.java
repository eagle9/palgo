public class Solution {
    // worst case is  [1,1,1,1... 1] with target = 0
    // can not use binary division, time is O(n)
    // so why not just a for loop
    // not test if you can use binary division, but to see if you can think of the worst case
    public boolean search(int[] A, int target) {
        for (int i = 0; i < A.length; i ++) {
            if (A[i] == target) {
                return true;
            }
        }
        return false;
    }
}

