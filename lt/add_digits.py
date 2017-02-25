#No 258 class Solution(object):
    #recursive method
    def addDigits2(self, num):
        """
        :type num: int
        :rtype: int
        """
        snum = str(num)
        sum = 0
        for c in snum:
            sum += int(c)
        if sum < 10:
            return sum
        else:
            return self.addDigits(sum)
            
    #O(1) using math, to figure out the math yet
    
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        elif num % 9 == 0:
            return 9
        return num%9
class Solution(object):
    #recursive method
    def addDigits2(self, num):
        """
        :type num: int
        :rtype: int
        """
        snum = str(num)
        sum = 0
        for c in snum:
            sum += int(c)
        if sum < 10:
            return sum
        else:
            return self.addDigits(sum)
            
    #O(1) using math, to figure out the math yet
    
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        elif num % 9 == 0:
            return 9
        return num%9
