class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end
class Point:
    def __init__(self,hour,delta):
        self.hour = hour
        self.delta = delta
class Solution:
    #given a list of each person's intervals, find all free time windows from 0 to 24 
    def find_all_free(self, calendars):
        points = []
        for calendar in calendars:
            for i in calendar:
                points.append(Point(i.start,1))
                points.append(Point(i.end,-1))
        points.sort(key=lambda p: p.hour)
        nBusy = 0 #track number of busy people
        hour = 0
        result = []
        for point in points:
            if nBusy == 0: #free for all persons
                if hour < point.hour:
                    result.append(Interval(hour,point.hour))
            hour = point.hour #update hour moving forward 
            nBusy += point.delta
        if hour < 24:
            result.append(Interval(hour,24))
        return result
calendars = [ [ Interval(2,4), Interval(6,7)], [Interval(3,5), Interval(6,9)] ] 
s = Solution()
result = s.find_all_free(calendars)
for i in result:
    print(i.start,i.end)





