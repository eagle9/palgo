/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Find in Mountain Array.
Memory Usage: 41.5 MB, less than 100.00% of Java online submissions for Find in Mountain Array.
*/
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int len = mountainArr.length();
        if (len == 0) return -1;
        int left = 1, right = len-2, mid = 0;
        while (left < right) {
            mid = left + (right - left)/2;
            int x = mountainArr.get(mid-1);
            int cur = mountainArr.get(mid);
            int y = mountainArr.get(mid+1);
            if (x < cur && cur < y) left = mid+1;
            else if (x > cur && cur > y) right = mid;
            else break; //x < cur > y
        }
        
        //peak exists, so we will find peak index which is mid
        int iPeak = mid;
        left = 0; 
        right = iPeak;
        while (left < right) {
            mid = left + (right - left)/2;
            if (target == mountainArr.get(mid)) return mid;
            else if (target < mountainArr.get(mid)) right = mid;
            else left = mid+1;
        }
        if (target == mountainArr.get(left)) return left;
        
        left = iPeak;
        right = len-1;
        while (left < right) {
            mid = left + (right - left)/2;
            if (target == mountainArr.get(mid)) return mid;
            else if (target < mountainArr.get(mid)) left = mid+1;
            else right = mid;
        }
        if (target == mountainArr.get(left)) return left;
        return -1;
    }
}


