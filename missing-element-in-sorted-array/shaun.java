package org.voyiger.algo;

import org.junit.Test;

/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

Example 1:

Input: A = [4,7,9,10], K = 1

Output: 5
Explanation:
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation:
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: A = [1,2,4], K = 3
Output: 6
Explanation:
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
Note:

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8

idea --- sorted array, naturally binary search
think how to control 1. search direction; 2. be careful with iteration and exit condition
 */
public class MissingElementInSortedArray {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        if(nums[n - 1] - nums[0] - (n - 1 - 0) < k){
            return nums[n - 1] + k - missCount(nums, n - 1);
        }

        int l = 0;
        int r = n - 1;

        while(l < r){
            int mid = l + (r - l) / 2;
            if(missCount(nums, mid) < k){
                l = mid + 1;
                //can you do l = mid, no!!!! if r-l = 1, then mid = l, will loop forever
            }else{ //missing count >= k, push left
                r = mid;
            }
        }
        //now l == r

        return nums[l - 1] + k - missCount(nums, l - 1);
    }

    //missing number count from 0 to index=mid
    //A = [4,7,9,10], mid = 2, missing number count from 4 to 9 is  568 = 3 = 9-4 - 2
    private int missCount(int [] nums, int mid){
        return nums[mid] - nums[0] - mid;
    }

    @Test
    public void test() {
        int [] A = {4,7,9,10};
        int K = 3;
        int res = missingElement(A, K);
        System.out.println("res = " + res);
    }
}

