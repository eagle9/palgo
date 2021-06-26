class Solution(object):
#my own design 
    def convertToBase7(self, num):
        if num == 0: return '0'
        q = num
        if num < 0: q = -q
        res = []
        while q > 0:
            digit = q % 7
            res.append(str(digit))
            q = q/7
        res.reverse()
        str1 = ''.join(res)
        if num < 0: str1 = '-' + str1
        return str1
#kamyu
# Time:  O(1)
# Space: O(1)

# Given an integer, return its base 7 string representation.
#
# Example 1:
# Input: 100
# Output: "202"
# Example 2:
# Input: -7
# Output: "-10"
# Note: The input will be in range of [-1e7, 1e7].

class Solution2(object):
    def convertToBase7(self, num):
        if num < 0: return '-' + self.convertToBase7(-num)
        result = ''
        while num:
            result = str(num % 7) + result
            num //= 7
        return result if result else '0'


class Solution3(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0: return '-' + self.convertToBase7(-num)
        if num < 7: return str(num)
        return self.convertToBase7(num // 7) + str(num % 7)

print Solution().convertToBase7(100)
print Solution().convertToBase7(0)
print Solution().convertToBase7(-7)
