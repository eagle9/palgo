//wrong answer, not clear about direction 
class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> c(n,1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i-1] > ratings[i]) c[i-1] = c[i]+1;
        }
        
        for (int i = n-2; i >=0; --i ) {
            if (ratings[i+1] > ratings[i]) {
                if (c[i+1] <= c[i]) c[i+1] = c[i] + 1;
            }
        }
        
        return accumulate(c.begin(), c.end(), 0);
    }
};

//shaun got deeper understanding about enforcing the rules for each child considering his left and right
//runtime 24ms, faster than 95%, mem less than 34%
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> c(n,1);  //at least 1 candy
        //each child has more candies than his left when his rating is higher
        //enfore c[i] = c[i-1]+1 when ratings[i] >, go from left to right since ci depends on left
        //child 0 does not have left neighbor, so start from 1
        for (int i = 1; i < n; ++i) {
            if (ratings[i-1] < ratings[i]) {
                if (c[i] <= c[i-1]) c[i] = c[i-1]+1;
            }
        }
        
        //each child has more candies than his right when his rating is higher
        //c[i] = c[i+1]+1 when ratings[i] >, loop from right to left, 
        //n-1 does not have right neighbor, so start from n-2
        for (int i = n-2; i >=0; --i ) {
            if (ratings[i] > ratings[i+1]) {
                if (c[i] <= c[i+1]) c[i] = c[i+1] + 1;
            }
        }
        
        int res = 0;
        for (auto i: c) {
            res += i;
        }
        return res;
        //return accumulate(c.begin(), c.end(), 0);
    }
};
