'''
Created on Feb 14, 2015

@author: Shaun
public int majorityElement(int[] num) {
        int n = num.length;
        int candidate = num[0], counter = 0;
        for (int i : num) {
            if (counter == 0) {
                candidate = i;
                counter = 1;
            } else {
                if (i == candidate) {
                    counter++;
                } else {
                    counter--;
                }
            }
        }

'''
class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num): #123 ms average speed
        
        candidate = num[0]
        counter = 0
        for i in num:
            if counter == 0:
                candidate = i
                counter = 1
            else:
                if i == candidate:
                    counter+=1
                else:
                    counter-=1
        return candidate
    def majorityElement2(self, num):
        n = len(num)
        #sorted[num]; return num[n>>1]  does not work
        return sorted(num)[n>>1]  #n>>1 is faster than /2
        
        
if __name__ == '__main__':
    sol = Solution()
    print sol.majorityElement2([1,2,3]), sol.majorityElement([1,2,3])
    print sol.majorityElement2([2,2,3]), sol.majorityElement([2,2,3])
    