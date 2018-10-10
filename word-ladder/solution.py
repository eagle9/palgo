#adapted from jiadai c++, Your submission beats 46.20% Submissions!
from string import ascii_lowercase
class Solution:
    """
    @param: start: a string
    @param: end: a string
    @param: dict: a set of string
    @return: An integer
    """
    def ladderLength(self,start, end, dict1):
        #write your code here
        dict1.add(end)
        Q = [start]
        visited = set()
        step = 0
        while Q:
            step += 1
            qs = len(Q)
            for i in range(qs):
                word = Q.pop(0)
                if word == end: #found and return
                    return step
                # try to change a single char at position j
                for  j in range(len(word)):
		    #convert the word to list of char, since string is immutaable in python
                    clist = [x for x in word]
                    for c in ascii_lowercase:
                        if c == word[j]:
                            continue
			#try a differ char at position j
                        clist[j] = c
                        word2 = ''.join(clist)
                        if word2 not in dict1:
                            continue
                        if word2 not in visited:
                            Q.append(word2)
                            visited.add(word2)

        return 0 #getting here means
