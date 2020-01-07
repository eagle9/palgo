1004. Max Consecutive Ones III
Medium 497 9 Favorite Share

Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

Example 1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
Accepted 26K
Submissions 46.8K

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Facebook | 7 Amazon | 2

Longest Substring with At Most K Distinct Characters Hard
Longest Repeating Character Replacement Medium
Max Consecutive Ones Easy
Max Consecutive Ones II Medium

Topic: Two Pointers, Sliding window

Hint 1
One thing's for sure, we will only flip a zero if it extends an existing window of 1s. Otherwise, there's no point in doing it, right? Think Sliding Window!
Hint 2
Since we know this problem can be solved using the sliding window construct, we might as well focus in that direction for hints. Basically, in a given window, we can never have > K zeros, right?
Hint 3
We don't have a fixed size window in this case. The window size can grow and shrink depending upon the number of zeros we have (we don't actually have to flip the zeros here!).
Hint 4
The way to shrink or expand a window would be based on the number of zeros that can still be flipped and so on.
