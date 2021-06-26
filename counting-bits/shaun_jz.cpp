//jz dp class idea number of 1 bits f(i) = f(i>>1) + i % 2
// break i into lowest bit and 2-32 bits, or i%2 and i>>1
// it is easy to see f(i) = f(i >> 1) + i%2
//runtime 52ms, faster than 100%, memory less than 73%
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1); //number of 1 bits of number i, dp[i]
        dp[0] = 0;
        if (num == 0) return dp;
        dp[1] = 1;
        if (num == 1) return dp;
        for (int i = 2; i <= num; ++i) {
            dp[i] = dp[i>>1] + i %2;
        }
        
        return dp;
    }
    
};


//shaun's original idea, first sub wrong answer, could get it accepted, idea not clean, hard to get it right
class Solution0 {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        vector<int> c10(num+1);
        vector<int> c11(num+1);
        
        
        dp[0] = 0;
        if (num == 0) return dp;
        dp[1] = 1;
        if (num == 1) return dp;
        //now num >= 2
        c10[0] = 0;
        c11[0] = 0;
        c10[1] = 1;  //c10[i]  number i count of consecutives 1 bits from lowest
        c11[0] = 0;  //c11[i] number i count of consecutive 1 bits from second lowest
        for (int i = 2; i <= num; ++i) {
            if (i-1 % 2 == 0) {
                //i-1 is even
                dp[i] = dp[i-1] + 1;
                c10[i] = c11[i-1] + 1;
                c11[i] = c10[i-1];
            }
            else {// i % 2 == 0 
                //i-1 is odd
                //c10[i-1]    011111     1    11
                //c11[i-1]     01111     10   100
                //add 1        100000
                dp[i] = dp[i-1] - c10[i-1] + 1;
                c10[i] = 0;
                c11[i] = c10[i-1] == 1? 1: 0;
            }
        }
        return dp;
                
    }
};

/* idea
input a number n
output: an array of count of bits for 0 to n

dp[0] = 0
dp[1] = 1
c10[0] = 0
c10[1] = 1   c10[i]  number i count of consecutives 1 bits from lowest
c11[0] = 0   c11[i] number i count of consecutive 1 bits from second lowest
dp[i] = from dp[i-1] ???  
    if i-1 % 2 == 0 
        dp[i] = dp[i-1] + 1
        c10[i] = c11[i-1] + 1
        c11[i] = c10[i-1]
    else // i % 2 == 0
        i-1 is odd
        c10[i-1]     011111     1    11
        c11[i-1]     01111     10   100
        add 1        100000
        dp[i] = dp[i-1] - c10[i-1] + 1
        c10[i] = 0
        c11[i] = c10[i-1] == 1? 1: 0
        
        add 1 + 1, carry forward
        second digit 0,   -1
        second digit 1, carry forward
        how many 1 from right?    0011111
        -k +1
        only know 1 count, not know its positions
        we can store this info during the loop though, only for current number

i   dp   c10   c11
0   0     0     0
1   1     1     0
2   1     0     1 
3   2     2     1
4   1     
5   2
*/
