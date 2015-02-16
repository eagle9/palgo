'''
Created on Feb 15, 2015

@author: Shaun
'''
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):   #43ms faster than average
        a = version1.split('.')
        b = version2.split('.')
        n1 = len(a)
        n2 = len(b)
        m = min(n1,n2)
        for i in range(m):
            diff = int(a[i]) - int(b[i])
            if diff == 0: continue
            else: return 1 if diff > 0 else -1
        #tied so far
        #edge case 1  vs 1.0
        if n1 > n2:
            if int(a[m]) > 0: return 1
            else: return 0
        if n1 < n2: 
            if int(b[m]) > 0: return -1
            else: return 0
        #tied and same length
        return 0
            
            