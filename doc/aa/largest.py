'''
Created on Feb 10, 2015

@author: XY1267
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Input:    [0,0]
Output:    "00"
Expected:    "0"
'''
class Larg:
    def largestNumber(self, num):
        a = sorted(num,self.cmp,reverse=True)
        if a[0] == 0:  #max(a) == 0
            return '0'
        
        a = [str(x) for x in a]
        return ''.join(a)
        ''''
        i = 0
        while int(a[i]) == 0:
            if i == len(a)-1: break
            #print a[i]
            i += 1
            
        return "".join(a[i:])
        '''
    
    def cmp(self,x,y):
        sx,sy = str(x), str(y)
        xy = sx + sy
        yx = sy + sx
        if xy > yx: return 1
        if xy < yx: return -1
        if xy == yx: return 0
         
        
if __name__ == '__main__':         
    a = [3, 30, 34, 5, 9]
    print Larg().largestNumber(a)
    a= [0,0]
    print Larg().largestNumber(a)
    