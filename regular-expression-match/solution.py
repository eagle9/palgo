#adapted from jz java, Your submission beats 100.00% Submissions!

#similar to the solution to wildcard matching, memoization search is used.
class Solution:
    '''
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
    '''
    def isMatch(self, s, p):
        if (s == None or p == None):
            return False

        #boolean[][] memo = new boolean[s.length()][p.length()];
        memo    = [[ None for i in range(len(p))] for j in range(len(s)) ]
        visited = [[ None for i in range(len(p))] for j in range(len(s)) ]
        return self.isMatchHelper(s, 0, p, 0, memo, visited)

    def isMatchHelper(self, s, sIndex, p, pIndex, memo, visited):
        #"" == ""
        if pIndex == len(p):
            return sIndex == len(s)

        if sIndex == len(s):
            return self.isEmpty(p, pIndex)

        if visited[sIndex][pIndex]:
            return memo[sIndex][pIndex]
            
        sChar = s[sIndex]
        pChar = p[pIndex]
        match = None

        #consider a* as a bundle
        if (pIndex + 1 < len(p) and p[pIndex + 1] == '*'):
            match = self.isMatchHelper(s, sIndex, p, pIndex + 2, memo, visited) or self.charMatch(sChar, pChar) and self.isMatchHelper(s, sIndex + 1, p, pIndex, memo, visited)
        else:
            match = self.charMatch(sChar, pChar) and  self.isMatchHelper(s, sIndex + 1, p, pIndex + 1, memo, visited)

        visited[sIndex][pIndex] = True
        memo[sIndex][pIndex] = match
        return match
        
    def charMatch(self,sChar, pChar):
        return sChar == pChar or pChar == '.'

    def isEmpty(self, p, pIndex):
        for i in range(pIndex, len(p),2):
            if i + 1 >= len(p) or p[i + 1] != '*':
                return False
        return True

