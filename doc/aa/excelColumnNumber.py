'''
Created on Feb 14, 2015

@author: Shaun
'''
from operator import pos
class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        res = 0
        t = 1
        
        for i in range( len(s)-1,-1,-1):
            n = ord(s[i]) - ord('A') + 1
            #print n, t
            
            res += n*t
            t*= 26
        return res 
    
if __name__ == '__main__':
    print Solution().titleToNumber('AB')  