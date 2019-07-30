//runtime 4ms, faster than 80%, mem less than 88%
//shaun own idea, with testing, accepted after 1 bug fix(signed integer overflow)
class Solution {
public:
    int titleToNumber(string s) {
        int n  = s.length();
        long sum =0; 
        for (int i = 0; i < n; ++i) {
            sum = sum* 26 + s[i] - 'A'+1; //bug signed integer overflow, int sum -> long sum
        }
        return (int)sum;
    }
};

/*
testing: 
A - Z: 1 - 26
AA: sum = 1, 1*26 + 1 = 27
ZY: sum = 25, 26*26 + 25 =  701

tricky case:
52 = 1*26 + 26
     A      Z
AZ: sum = 1,  Z: 1*26+ 26

*/
