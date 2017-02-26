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
        """
        res = []
        row_list = [set('qwertyyuiop'),set('asdfghjkl'),set('zxcvbnm')]
        for word in words:
            for row in row_list:
                if self.checkHelper(word.lower(),row): 
                    res.append(word)
        return res
