class Solution {
    
    //jz beats 100.00%
    //two key points: 
    //1)integer multiplication overflows, use long
    //2) loop condition start+1 < end, otherwise if no match, will stuck
    //start+1 = end, mid = start, rather than a number between start and end
    public boolean isPerfectSquare1(int num) {
        long start = 1, end = (long)num;
        //int start = 1, end = num;  wont' work, overflow
        long target = (long)num;
        //while(start + 1 < end){
        while(start +1 < end){ //TLE if start <= end
            long mid = start + (end - start) / 2;
            
            //int mid = start + (end - start)/2;
            if(mid * mid < target) {
                start = mid;
            }else{
                end = mid;
            }
        }
        /*
        if(start * start == (long)num || end * end == num)
            return true;
            */
        
        
        if(start * start == (long)num || end * end == (long)num){
            return true;
        }
        
        return false;
    }
    
    //shaun's try, TLE when int i and prev
    //beats 27% when long i, prev
    public boolean isPerfectSquare(int num) {
        if (num ==1)
            return true;
        long i = 2, prev = 1;
        while (true) {
            long guess = i*i;
            if (guess == (long)num)
                return true;
            if (guess < num) {
                prev = i;
                i *= 2;
            }
            else 
                break;
        }
        for (long j = prev; j<i; j++) {
            if (j*j == (long) num) {
                return true;
            }
        }
        return false;
        
    }
    //simple binary search TLE, c++ works but not java
    public boolean isPerfectSquare2222(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int mid = left + (right - left)/2;
            long t = mid* mid;
            if (t - num == 0)
                return true;
            if (t < num) {
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        return false;
    }
}
