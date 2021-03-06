727. Minimum Window Subsequence
Hard 352 16 Favorite Share

Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 5

Topic: Dynamic programming, sliding window
Similar:  Minimum window substring(hard), longest continuous increasing subsequence(easy)

Hint 1:
Let dp[j][e] = s be the largest index for which S[s:e+1] has T[:j] as a substring.

