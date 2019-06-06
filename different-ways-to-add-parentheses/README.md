241. Different Ways to Add Parentheses
Medium

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:
Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 3 

Similar:
Unique Binary Search Trees II Medium
Basic Calculator Hard
Expression Add Operators Hard

Topic: Divide and Conquer

idea forming, cutting angle
hua, split the string at every operator, not easy to come up with. 

