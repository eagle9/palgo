class Solution:
    """
    @param: reader: An instance of ArrayReader.
    @param: target: An integer
    @return: An integer which is the first index of target.
    #Your submission beats 83.20% Submissions!
    #Your submission beats 83.20% Submissions! after update

    #based on jiadai
    """
    def searchBigSortedArray(self, reader, target):
        # write your code here
        '''
        i = 1
        while reader.get(i-1) < target:
            i *= 2
        start,end = i/2, i-1
        '''
        #shaun update with i started from 0
        i = 0
        while reader.get(i) < target:  #exit condition: the number at i >= target
            if i == 0:
                i += 1
            else: 
                i *= 2
        start,end = i/2, i        
        
        
        while start + 1 < end:
            mid = (start + end)/2
            if reader.get(mid) < target:
                start = mid + 1
            else:
                end = mid
        
        if reader.get(start) == target:
            return start
        elif reader.get(end) == target:
            return end
        return -1
