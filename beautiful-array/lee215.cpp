/*
Runtime: 36 ms, faster than 17.95% of C++ online submissions for Beautiful Array.
Memory Usage: 20.5 MB, less than 8.70% of C++ online submissions for Beautiful Array.

lee215 idea, construct for smaller problems
no average in between!!!
use python or c++ vector is much easier to implement
1
1 2
1 2 ->1 3, 2 ---> 1 3 2
4:   1 3,  2 4 ---->  1 3 2 4
*/

class Solution {
public:
    vector<int> beautifulArray(int N){
        vector<int>ans;
        if(N==1){
            ans.push_back(1);
            return ans;
        }
        else {
            vector<int> odd = beautifulArray(N/2+ N%2);
            int sz = odd.size();
            for(int i=0;i<sz;i++) ans.push_back(2*odd[i]-1);
            vector<int> even = beautifulArray(N/2);
            sz = even.size();
            for(int i =0; i<sz;i++) ans.push_back(2*even[i]);
        }
        return ans;
    }
 
};

