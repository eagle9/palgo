774. Minimize Max Distance to Gas Station
Hard
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.

Topic: Binary search

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 3

Similar: Koko eating bananas
Hint 1: Use a binary search. We'll binary search the monotone function "possible(D) = can we use K or less gas stations to ensure each adjacent distance between gas stations is at most D?"
