#beats 100.00%, https://lefttree.gitbooks.io/leetcode-categories/content/Math/mathWithoutOperator/divideTwoIntegers.html
#divide two integers without using multiplication, division and mod operator
#9/2
# 2 4 8 16 > 9, i = 3, doubling 3 times, over 9
#doubling 2 times to get 8,   9-8 = 1,   1 < 2 the divisor, done. 
# result = 1 << 2 = 4
# 44/3,   3-6-12-24... 48,  res = 0+3,  res = 1<<3 = 8, dividend = 44-24 = 20
# 20/3,   3-6-12..24 ,   res = 8+1<<2 = 12, divident = 20- 12 = 8
# 8/3,  3-6..12,   res = 12  + 1<<1 = 14, divdend = 8 - 6= 2 < 3 the divisor
#    final result = 14 
class Solution:
    """
    @param dividend: the dividend
    @param divisor: the divisor
    @return: the result
    """
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = 1
        if (dividend < 0) ^ (divisor < 0): #^ is bit or
            sign = -1

        if dividend == 0:
            return 0
        if divisor == 0:
            return

        dividend = abs(dividend)
        divisor = abs(divisor)

        result = 0

        while dividend >= divisor:
            i = 0
            a = divisor 
            while a <= dividend: # double divisor when it is <= dividend
                a = a << 1
                i += 1
            #now a > dividend, divisor doubled i times
            result += 1 << (i-1)
            dividend -= (a >> 1) #divident minus Q*divisor
        
        if sign < 0:
            result = -result
        
        N = 2**31-1
        #prevent overflow
        if result > N:
            return N
        else:
            return result
        
