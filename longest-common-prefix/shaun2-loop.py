#Runtime: 32 ms, faster than 67.59% of Python3 online submissions for Longest Common Prefix.
class Solution:
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ""
        prefix = strs[0]
        for i in range(1,len(strs)):
            prefix = self.find_prefix(strs[i],prefix)   #bug fix, add self. 
            if len(prefix) == 0: return prefix
        return prefix
    
        
    def find_prefix(self,a,b):
        i = 0
        len1 = min(len(a),len(b))
        while i < len1:
            if a[i] == b[i]: i+=1
            else: break
        return a[0:i]
