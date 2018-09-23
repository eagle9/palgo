#adapted from jz java, Your submission beats 69.09% Submissions!

class Solution:
    '''
     * @param : a string to be split
     * @return: all possible split string array
    '''
    def splitString(self,s):
        res = []
        local = []

        self.dfs(s,  local, res)

        return res



    #a general dfs loop
    # s is the string, each time choose the first char, then choose the second char, then pass on the remaining characters for recursion

    def dfs(self, s,  local, res):
        if s == "":
            res.append(local.copy())
            return

        for  i  in range(1, 3):
            if i <= len(s):
                local.append(s[0: i])
                self.dfs(s[i: len(s)], local, res)
                local.pop()

