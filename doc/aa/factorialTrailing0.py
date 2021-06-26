'''
Created on Feb 14, 2015

@author: Shaun
Given an integer n, return the number of trailing zeroes in n!.
'''
class Solution:
    # @return an integer
    #http://bookshadow.com/weblog/2014/12/30/leetcode-factorial-trailing-zeroes/
    #n! trailing 0 count = n! prime factor 5 count
    #          = floor(n/5) + floor(n/25) + floor(n/125) + ....
    def trailingZeroes(self, n):   #49 ms faster than average
        x = 5
        ans = 0
        while n >= x:
            ans += n / x
            x *= 5
        return ans