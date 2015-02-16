'''
Created on Feb 8, 2015

@author: XY1267
'''

dict = ["cat", "cats", "and", "sand", "dog"]

solu =  ["cats and dog", "cat sand dog"]
import time

class Slow:
    
    def __wbreak(self,s,start,sentence,res):
        if start >= len(s):  #edge case of recursion
            res.append(sentence) #res is list of sentences
            return
        '''s = ''
        for i in range( start,len(s)):
            s += s[i]
            '''
        for i in range( start, len(s)):
            s = s[start:i+1] #from start to i
            if s in self.dict:
                newSentence = sentence +" " + s if len(sentence) > 0 else s #grow the sentence
                self.__wbreak(s,i+1,newSentence,res)
    def wordBreak(self, s, dict):
        res = []
        self.dict = dict
        self.__wbreak(s,0,'',res)
        return res

class Fast:
    def  wordBreak(self, s, dict):
        length = len(s)
    
        tail = []
        temp = []
        
        for i in range(length+1):
            tail.append([])
        
        possible = []
        for i in range(length): possible.append(False)
        possible.append(True)
        
        for i in range(length-1,-1,-1):
            position = i
            while position < length:
                position += 1
    
                if possible[position] and s[i:position] in dict:
                
                    temp = tail[position];
                    possible[i] = True;
    
                    if len(temp) != 0:
                        for j in range( len(temp)):
                            tail[i].append( s[i:position] + " " + temp[j])
                    else:
                        tail[i].append(s[i:position]);
                
    
        return tail[0]
    
         
if __name__ == '__main__':
    s = "catsanddog"
    
    for runner in [Fast(), Slow()]:
        start = time.time()
        res = []
        for i in range(100):
            res = runner.wordBreak(s,dict)
        print res
        end = time.time()
        duration = end - start
        print runner,"duration = %.10f msec" % (duration * 1000)
    
    
     
    
    