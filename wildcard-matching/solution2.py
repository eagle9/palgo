class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        #credit to http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html

        i,j,s_star,p_star = 0,0,0,-1
        while i<len(s):
            if j<len(p) and (s[i]==p[j] or p[j]=='?'):
                i,j = i+1,j+1
            elif j<len(p) and p[j]=='*':
                s_star,p_star = i,j
                j+=1
            elif p_star!=-1:
                s_star +=1
                i,j = s_star,p_star+1
            else:
                return False


        while j<len(p) and p[j]=='*':
            j+=1
        return True if j==len(p) else False
