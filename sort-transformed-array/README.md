360. Sort Transformed Array
Medium 262 74 Favorite Share

Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]

Accepted
30.3K
Submissions
63.7K

0 ~ 6 months
6 months ~ 1 year1 year ~ 2 years
Google | 3

Similar:
Squares of a Sorted Array Easy

x^2 + x will form a parabola.
Parameter A in: A * x^2 + B * x + C dictates the shape of the parabola.
Positive A means the parabola remains concave (high-low-high), but negative A inverts the parabola to be convex (low-high-low).

Topic: Math, Two Pointers
