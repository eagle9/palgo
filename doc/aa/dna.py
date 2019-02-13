'''
Created on Feb 14, 2015

@author: Shaun
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
'''

class Solution:
    # @param s, a string
    # @return a list of strings
    def findRepeatedDnaSequences(self, s):  #time limit exceeded, O(N^2)
        N = len(s)
        res = []
        for start in range(N - 10):
            
            seq = s[start:start+10]
            #print seq
            if seq in s[start+1:N]: res.append(seq)
        return res
    
    def findRepeatedDnaSequences2(self, s):  #115ms
        N = len(s)
        dict = {}
        for start in range(N - 10+1):
            
            seq = s[start:start+10]
            if seq not in dict: dict[seq] = 1
            else: dict[seq] += 1
            
        res = []
        for seq in dict: 
            if dict[seq] > 1: res.append(seq)
        return res
    
    
    def findRepeatedDnaSequences3(self, s):  #132ms
        ans = []
        valCnt = dict()
        map = {'A' : 0, 'C' : 1, 'G': 2, 'T' : 3}
        sum = 0
        for x in range(len(s)):
            sum = (sum * 4 + map[s[x]]) & 0xFFFFF
            if x < 9:
                continue
            valCnt[sum] = valCnt.get(sum, 0) + 1
            if valCnt[sum] == 2:
                ans.append(s[x - 9 : x + 1])
        return ans
if __name__ == '__main__':
    solution = Solution()
    #print solution.findRepeatedDnaSequences2("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")
    print solution.findRepeatedDnaSequences2("AAAAAAAAAAA")
    print solution.findRepeatedDnaSequences3("AAAAAAAAAAA")