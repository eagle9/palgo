#adapted jz recursive java, , use dfs recursive template
#Your submission beats 87.11% Submissions!
class Solution:
    def stringPermutation2(self, str1):
        result = []
        if str1 == None:
            return result
        if len(str1) == 0:
            result.append("")
            return result
        #clist = [c for c in str1]
        #clist.sort() #list.sort() return None, but list is sorted 
        #str1 = ''.join( clist )
        #one liner with sorted function, can not use list.sort()
        str1 = ''.join( sorted([c for c in str1]))
        visited = [False for i in range(len(str1))]
        self.dfs(str1, "", result, visited)
        return result

    def dfs(self, str1, subset, result, visited):
        if len(subset) == len(str1):
            #exit of recursion
            result.append(subset)
            return

        for i  in range( len(str1) ):
            if visited[i]:
                continue

            if (i > 0 and str1[i]== str1[i - 1] and not visited[i - 1]):
                #remove duplicates
                continue
    
            visited[i] = True
            self.dfs(str1, subset + str1[i], result, visited)
            visited[i] = False

