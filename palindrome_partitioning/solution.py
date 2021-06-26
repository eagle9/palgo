#adapted from jiadai c++ -> java , Your submission beats 63.48% Submissions!
class Solution:
    """
    @param: s: A string
    @return: A list of lists of string
    """

    def partition(self, s):
        #write your code here
        result = []
        n = len(s)
        if (n == 0):
            return result

        isPalindrome =[ [None for i in range(n)] for i in range(n)]
        for j in range(n):
            for i in range(j,-1,-1):
                #if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) { //c++
                if (s[i] == s[j] and (j - i < 2 or isPalindrome[i + 1][j - 1])):
                    isPalindrome[i][j] = True
        path = []
        self.dfs(s, 0, isPalindrome, path, result)
        return result

    def dfs(self,s, start, isPalindrome, path, result):
        if start == len(s):
            result.append(path.copy())
            return

        for i in range(start, len(s)):
            if isPalindrome[start][i]:
                #path.push_back(s.substr(start, i - start + 1));
                #c++ string.substr(start,len) return a string that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
                path.append(s[start: i + 1]) #java String substring(startIndex, endIndex)
                self.dfs(s, i + 1, isPalindrome, path, result)
                path.pop()

