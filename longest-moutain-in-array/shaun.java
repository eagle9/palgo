/*
Runtime: 6 ms, faster than 66.52% of Java online submissions for Longest Mountain in Array.
Memory Usage: 39.7 MB
https://www.cnblogs.com/seyjs/p/9132045.html
i get the idea and coded from the idea. good easy to grasp. but suffered some loose details, fixed and accepted.  similar to huahua's with two dp array. idea is easy to understand and easy to implement
??? how to reduce the dimension of left and right array????
*/
class Solution1 {
    public int longestMountain(int[] A) {
        int n = A.length;
        if (n == 0) return 0;
        
        int [] left = new int[n];
        int [] right= new int[n];
        left[0] = 0;
        //left side increasing sub array len
        for (int i = 1; i < n; i++) {
            if (A[i-1] < A[i]) left[i]= left[i-1]+1;
            else left[i] = 0;
        }
        
        //right side decreasing sub array len
        right[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            if (A[i] > A[i+1]) right[i] = right[i+1]+1;
            else right[i] = 0;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            //previous shaun wrote len = left[i] + 1 + right[i], does not satisfy the mountain property, left sub array len must > 0 and right sub array len > 0 too
            int len = (left[i] > 0 && right[i] > 0)? left[i] + 1 + right[i]: 0;
            res = Math.max(res, len );
        }
        return res;
    }
    
    
}

//shaun own first try, index out of bound then wrong answer
class Solution0 {
    public int longestMountain(int[] A) {
        int start  = 0, res = 0; 
        boolean up = false, down = false;
        for (int i = 1; i < A.length; i++) {
            if (!down && A[i-1] < A[i]) {
                up = true;
                start = i-1;
            }
            else if (up && A[i-1] > A[i]) {
                down = true;
                up = false;
            }
            else if (down && A[i-1] < A[i]) {
                down = false;
                up = true;
                int len = i - start;
                res = Math.max(res, len);
                start = i-1;
            }
            
        }
        return res;
    }
}
/*
lt awice two pointer. my original idea is like this, but i was not able to clean it out

while loop inside while loop, expanding the 2nd pointer

Runtime: 5 ms, faster than 95.69% of Java online submissions for Longest Mountain in Array.
Memory Usage: 39.4 MB
*/

class Solution {
    public int longestMountain(int[] A) {
        int N = A.length;
        int ans = 0, base = 0;
        while (base < N) {
            int end = base;
            // if base is a left-boundary
            if (end <= N-2 && A[end] < A[end + 1]) {
                // set end to the peak of this potential mountain
                while (end <= N -2 && A[end] < A[end + 1]) end++;

                // if end is really a peak..
                if (end <= N -2 && A[end] > A[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end <= N-2 && A[end] > A[end + 1]) end++;
                    // record candidate answer
                    ans = Math.max(ans, end - base + 1);
                }
            }

            base = Math.max(end, base + 1); //passed a mountain, base = end, otherwise +1 
        }

        return ans;
    }
}

