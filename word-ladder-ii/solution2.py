#based on jiadai c++
#not yet working, compare to jiadai c++
from string import ascii_lowercase
class Solution:
    '''
       @param start, a string
       @param end, a string
       @param dict, a set of string
       @return a list of lists of string
    '''
    def findLadders(self,start, end, dict1):
        #write your code here
        result = []
        if len(start) == 0:
            return result

        dict1.add(end)

        if self.bfs(start, end, dict1):
            path = []
            path.append(start)
            self.dfs(start, end, path, result)
        return result
    
    #unordered_map<string, vector<string>> nextWord;
    nextWord = {} #dict string: []
    #unordered_map<string, int> distance;
    distance = {} #dict string:int
    
    def bfs(self,start, end, dict1):
        Q = [start]
        self.distance[start] = 0
        step = 0;
        done = False
        while Q:
            qs = len(Q)
            step += 1
            for i in range(qs):
                s = Q.pop(0)
                if s == end:
                    return True
                snext = []
                for j in range(len(start)):
                    word = [x for x in s]
                    for c in ascii_lowercase:
                        word[j] = c
                        word2 = ''.join(word)
                        if c == s[j] or word2 not in dict1:
                            continue
                        if word2 not in self.distance:
                            Q.append(word2)
                            self.distance[word2] = step
                        snext.append(word2)
                self.nextWord[s] = snext

        return done
    
    def dfs(self,start, end, path, result):
        if start == end:
            result.append(path)
            return

        nw = self.nextWord[start]
        for  s in nw:
            if self.distance[s] == self.distance[start] + 1:
                path.append(s)
                self.dfs(s, end, path, result)
                path.pop()
