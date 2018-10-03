//jz beats 84.40%
//shaun modified, beats 86%
class Solution {
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
     //A goes up from head,  going down to tail
    public int findPeak(int[] A) {
        // write your code here
        int start = 1, end = A.length-2; 
        while(start + 1 <  end) { //exit start +1 = end, 1 number in between
            int mid = (start + end) / 2;
            if(A[mid - 1] > A[mid]) { //going down from mid-1 to mid  ^ from start to mid
                end = mid;
                
            }
            // now A[mid-1] < A[mid]  going up from m-1 to mid
            else if(A[mid] < A[mid + 1]) { //going up from mid to mid+1  ^ from mid to end
                start = mid;
                
            }else { //A[mid-1] < A[mid] && A[mid] > A[mid+1]
                return mid;
            }
            
            
        }
        //start +1 = end
        if(A[start] < A[end]) {
            return end; //why?  because end must go down
        } else {   //A[start] > A[end]
            return start;  //why? start must go up
        }
    }
    
    //jz original
    public int findPeak0(int[] A) {
        // write your code here
        int start = 1, end = A.length-2; 
        while(start + 1 <  end) {
            int mid = (start + end) / 2;
            if(A[mid - 1] > A[mid]) { //going down from mid-1 to mid  ^ from start to mid
                end = mid;
            }
            // now A[mid-1] <= A[mid]  going up from m-1 to mid
            else if(A[mid] < A[mid + 1]) { //going up from mid to mid+1  ^ from mid to end
                start = mid;
            } else {
                end = mid;
            }
        }
        if(A[start] < A[end]) {
            return end;
        } else { 
            return start;
        }
    }
}
