/*
idea forming: 
try each start, then go right and include only > numbers
time O(n^2), space O(1): only store the longest

time O(nlogn), logn may binary search

dp[i] stores the lis from 0 to i-1, sorted list
dp[i+1]= ? find nums[i] position in dp[i], then dp[i+1] = .... nums[i]
        put nums[i] at index found, O(1)
        then have to copy multiple elements, O(N)?
        s

logn is a hint to use binary search
shaun idea upon the hint and build the sorted lis with one iteration 

Runtime: 1 ms, faster than 86.31% of Java online submissions for Longest Increasing Subsequence.
Memory Usage: 37.6 MB, less than 34.00% of Java online submissions for Longest Increasing Subsequence.
*/
class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> seq = new ArrayList<>();
        
        for (int x: nums) {
            if (seq.isEmpty()) seq.add(x);
            else {
                if (x < seq.get(0)) seq.set(0,x);
                else if (x > seq.get(seq.size()-1)) {
                    seq.add(x);
                }else {
                    int index = binarySearch(seq, x);
                    seq.set(index,x);
                }
            }
        }
        return seq.size();
    }
    
    private int binarySearch(List<Integer> seq, int x) {
        int left = 0, right = seq.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (seq.get(mid) >= x) {
                right = mid;
            }else { // mid < x
                left = mid+1;
            }
                
        }
        //left == right now
        return left;
    }
}
