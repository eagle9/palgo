#ling huchong, use Queue
#Your submission beats 90.16% Submissions!
class MovingAverage:

    # Initialize your data structure here.
    def __init__(self,size):
        self.que = []
        self.size = size
        self.sum1 = 0

    def next(self,val):
        # Write your code here
        self.sum1 += val
        if len(self.que) == self.size:
            self.sum1 = self.sum1 - self.que.pop(0)
        
        self.que.append(val)
        return self.sum1 / len(self.que)
