#ling hucong, Your submission beats 83.80% Submissions!
#use dfs +  memo
#use a 2-d boolean array for memo, record s from sIndex postfix that can match p from pIndex postfix
#Your submission beats 100.00% Submissions!
class Solution:
    '''
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
    '''
    def isMatch(self,s, p):
        if (s == None or p == None):
            return False
        #boolean[][] memo = new boolean[s.length()][p.length()];  s rows and p columns
        memo =      [[None for i in range(len(p))] for j in range(len(s))]
        #memo =      [[None for i in range(len(s))] for j in range(len(p))] # this does not work, why?
        visited =   [[None for i in range(len(p))] for j in range(len(s))]
        return self.isMatchHelper(s, 0, p, 0, memo, visited)

    def isMatchHelper(self,s, sIndex, p, pIndex, memo, visited):
        # if p from pIndex is empty string, then s from sIndex must be empty for a match
        if pIndex == len(p):
            return sIndex == len(s)

        # if s from sIndex is empty, then p must all be *
        if sIndex == len(s):
            return self.allStar(p, pIndex)

        if visited[sIndex][pIndex]:
            return memo[sIndex][pIndex]

        sChar = s[sIndex]
        pChar = p[pIndex]
        match = None
        
        if pChar == '*':
            match = self.isMatchHelper(s, sIndex, p, pIndex + 1, memo, visited) or self.isMatchHelper(s, sIndex + 1, p, pIndex, memo, visited)
        else:
            match = self.charMatch(sChar, pChar) and self.isMatchHelper(s, sIndex + 1, p, pIndex + 1, memo, visited)

        visited[sIndex][pIndex] = True
        memo[sIndex][pIndex] = match
        return match

    def charMatch(self, sChar, pChar):
        return sChar == pChar or pChar == '?'

    def allStar(self, p, pIndex):
        for i in range(pIndex, len(p)):
            if p[i] != '*':
                return False
        return True
