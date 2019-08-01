406. Queue Reconstruction by Height
Medium 1691 191 Favorite Share

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 

Accepted 84,793 
Submissions 140,357
Contributor LeetCode

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 4 Amazon | 2

Similar:
Count of Smaller Numbers After Self Hard

Topic: Greedy

Hint 1:
What can you say about the position of the shortest person? 
Hint 2:
If the position of the shortest person is i, how many people would be in front of the shortest person?
Hint 3:
Once you fix the position of the shortest person, what can you say about the position of the second shortest person?
