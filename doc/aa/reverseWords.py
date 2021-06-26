'''
Created on Feb 9, 2015

@author: XY1267
'''
import re
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        words = []
        begin = False
        end = True
        word = ''
        for i in range( len(s)):
            if s[i] != ' ' and not begin:
                word = s[i]
                begin = True
                end = False
            elif s[i] == ' ' and not end:
                end = True
                begin = False
                words.append(word)
                word = ''
            elif begin and not end:
                word += s[i]
               
        #print words  
        # the following edge case missed first time      
        if not end:
            end = True
            words.append(word)
            
        L = len(words)
        steps = L/2
        for i in range(steps):
            words[i],words[L-i-1] = words[L-i-1],words[i] 
        res = ''
        for i,w in enumerate(words):
            if i == 0: res = w
            else: res += ' ' + w
        #print res
        return res
class Solution2:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        words = re.split("\s+",s)
        #print words
        words = filter(lambda x: len(x) > 0, words)
        #print words
        words.reverse()
        res = ' '.join(words)
        return res  
                                               
              
if __name__ == "__main__":
    s = " what a   good guy "
    res = Solution().reverseWords(s)
    print s, '--->', res
    
    res = Solution2().reverseWords(s)
    print s, '--->', res
     
    s = "a"
    res = Solution().reverseWords(s)
    print s, '--->', res        