/*
3 1 2 4
2 4 1 3

test2 with in place sorting:
3 2 4 1
4 2 1 3
1 2 3 4 5
4   3 5 1
shaun own idea and code accepted first sub
use another array is very simple, in place sorting is harder
this case, additional array is allowed
runtime 24ms, faster than 98%, mem less than 95%
*/
class Solution1 {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int oddIndex = n-1, evenIndex = 0;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (A[i] % 2 ==1) {
                res[oddIndex--] = A[i];
            }else {
                res[evenIndex++] = A[i]; 
            }
        }
        return res;
    }
};

//shaun own idea with inplace sorting, did some testing before submission
//cutting swap odd elements to oddIndex(start from n-1 and -- each time)
// similar to sort the colors problem??
//accepted first sub
//runtime 24ms, faster than 98%, mem less than 52%
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int oddIndex = n-1, evenIndex = 0;
        vector<int> res(n);
        for (int i = 0; i < oddIndex; ) {
            if (A[i] % 2 ==1) {
                swap(A[i], A[oddIndex--]);
                //unknown element in Ai now, i no change
            }else {
                //Ai is even, next i
                i++;
            }
        }
        return A;
    }
};
