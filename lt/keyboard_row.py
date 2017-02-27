#No. 500 keyboard row
class Solution(object):
    def checkHelper(self,word,row):
        """
        :type word: str
        :type row: set
        :rtype: True/False
        """
        for c in set(word):
            if c not in row: 
                return False
        #pass for tests
        return True
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
	my own initial try, only beat .7%
        """
        res = []
        row_list = [set('qwertyyuiop'),set('asdfghjkl'),set('zxcvbnm')]
        for word in words:
            for row in row_list:
                if self.checkHelper(word.lower(),row): 
                    res.append(word)
        return res

    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        rs = map(set, ['qwertyuiop','asdfghjkl','zxcvbnm'])
        ans = []
        for word in words:
            wset = set(word.lower())
	    #check subset, nice use of python built in functions 
            if any(wset <= rset for rset in rs):
                ans.append(word)
        return ans

