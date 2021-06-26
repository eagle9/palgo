'''
Created on Feb 15, 2015

@author: Shaun
cpp solution Runtime: 8 ms, faster than average
http://blog.csdn.net/u010367506/article/details/41943309
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left=0,right=num.size()-1;
        while(left<=right){
            if(left==right)
                return left;
            int mid=(left+right)/2;
            if(num[mid]<num[mid+1])
                left=mid+1;
            else
                right=mid;
        }
    }
};
'''
class Solution:  #Runtime: 61 ms, average, O(lgN)
    # @param num, a list of integer
    # @return an integer

    def findPeakElement(self, num):
        left, right = 0, len(num) - 1
        while left <= right:
            if left == right: return left
            mid = (left + right) >> 1
            if num[mid] < num[mid+1]:
                left = mid + 1
            else:
                right = mid
            
    def findPeakElement2(self,num):
        n = len(num)
        low,high = 0, n-1
        mid = 0
        while (low < high):
            mid = (high - low)/2
            if (  mid == 0 or num[mid] > num[mid-1] ) and ( mid == n-1 or  num[mid] > num[mid+1] ):
                return mid
            if (mid >0 and num[mid-1] > num[mid]):
                high = mid - 1
            else:
                low = mid + 1    
if __name__ == '__main__':
    arr = [0, 1, 2, 9, 7, 5, 4, 2, 1]
    s = Solution()
    print s.findPeakElement(arr)
    
    
'''
int findPeakElement(const vector<int> &num) {

    int n = num.size();
    int low = 0;
    int high = n - 1;

    int mid = 0, v1, v2;

    while ( low < high ) {

        // Find the index of middle element
        mid = low + ( high - low ) / 2;

        // Compare middle element with its neighbours (if neighbours exist)
        if ( ( mid == 0 || num[mid] > num[mid-1] ) && 
                ( mid == n-1 ||  num[mid] > num[mid+1] )  ){
            return mid;
        }

        // If middle element is not peak and its left neighbor is greater than it
        // then left half must have a peak element
        if (mid >0 && num[mid-1] > num[mid]){
            high = mid - 1;
        // If middle element is not peak and its right neighbor is greater than it
        // then right half must have a peak element
        }else{
            low = mid + 1;
        }

    }

    return low;
}
'''