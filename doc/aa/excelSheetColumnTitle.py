'''
Created on Feb 15, 2015

@author: Shaun
StringBuilder sb = new StringBuilder();
        while (n >= 1) {
            n--; // convert to zero start
            sb.append((char) ('A' + n % 26));
            n /= 26;
            if (n == 0) break;
        }
        sb.reverse();
        return sb.toString();
'''
from _ast import Num
class Solution:
    # @return a string
    def convertToTitle(self, num):
        res = ''
        while  num >=1:
            num -=1 #convert to zero start
            #res += chr( ord('A') + num % 26)
            res = chr( ord('A') + num % 26) + res
            num /= 26 
            
            if num == 0: break
        #return res[::-1]
        return res
    
    def convertToTitle2(self, num): # not working
        res = ''
        pos = 0
        dict = {}
        for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            pos+=1
            dict[pos] = c
        dict[0] = 'Z'
        if (num <= 26): return dict[num]   
        while  num >=1:
            
            res = dict[ num % 26 ] + res
            num /= 26 
            
            if num == 0: break
        return res
if __name__ == '__main__':
    sol = Solution()
    print sol.convertToTitle2(1*26)
    print sol.convertToTitle2(1*26 + 2)
    print sol.convertToTitle2(2*26**2 + 25*26+ 3)       