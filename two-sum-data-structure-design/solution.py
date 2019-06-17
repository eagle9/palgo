#Your submission beats 62.78% Submissions!
#based on jiadai c++
class TwoSum:
    def __init__(self):
        self.table = {}
    """
    @param: number: An integer
    @return: nothing
    """
    def add(self, number):
        # write your code here
        if number not in self.table: #for python, it is key to test k in dict
            self.table[number] = 1
        else:
            self.table[number] += 1
        
    """
    @param: value: An integer
    @return: Find if there exists any pair of numbers which sum is equal to the value.
    """
    def find(self, value):
        # write your code here
        for k in self.table:
            
            b = value - k
            if (k != b and b in self.table and self.table[b] > 0):
                return True
            if ( k== b and self.table[k] > 1):
                return True
        return False
