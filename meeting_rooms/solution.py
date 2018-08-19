
'''
 Definition of Interval:
 classs Interval:
 def __init__(self,start,end):
    self.start = start
    self.end = end
'''

#Your submission beats 100.00% Submissions!
class Solution:
    '''
     param intervals: an array of meeting time intervals
     @return: if a person could attend all meetings
    '''
    def canAttendMeetings(self,intervals):
        #Write your code here
        #intervals = sorted(intervals, key=lambda x: x.start)   #reverse = False
        intervals.sort(key=lambda x: x.start)
        for i in range(1,len(intervals)):
            if intervals[i].start < intervals[i - 1].end:
                return False
        #pass all tests
        return True
