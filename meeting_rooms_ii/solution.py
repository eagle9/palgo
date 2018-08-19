#Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
#jz linghu line sweeping algo
#Your submission beats 100.00% Submissions!

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def minMeetingRooms(self, intervals):
        points = []
        for interval in intervals:
            points.append((interval.start, 1))
            points.append((interval.end, -1))
            
        meeting_rooms = 0
        ongoing_meetings = 0
        #for _, delta in sorted(points):
        #for n, delta in sorted(points):
        for n, delta in sorted(points,key=lambda x: x[0]):
            ongoing_meetings += delta
            meeting_rooms = max(meeting_rooms, ongoing_meetings)
            print(n,delta,meeting_rooms)
            
        return meeting_rooms
intervals = []
for t in [(0,30),(5,10),(15,20)]:
    intervals.append(Interval(t[0],t[1]))
s = Solution()
nRooms = s.minMeetingRooms(intervals)
print(nRooms)
