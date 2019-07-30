/*
cutting: critical to list all typical cases:
kind of very tricky
shaun's own idea, accepted after many bug fixes
sounds easy, and so many traps for bugs
runtime 0ms, faster than 100%, mem less than 50%
1
A
26 = 1*26
Z
28 = 1*26 + 2
      A     B
     28/1       28%26
701 = 26*26 + 25
      Z       Y
      701/26        701%26

52 = 1*26 + 26
     A      Z
*/
class Solution {
public:
    //n is positive integer
    string convertToTitle(int n) {
        string res;
        while (n > 26) {
            int d = n%26;
            if (d == 0) {
                res.insert(res.begin(), 'Z');
                n -= 26;
            }else {
                res.insert(res.begin(), 'A' + d -1);
            }
            n = n/26;
        }
        //n <= 26 now
        res.insert(res.begin(), 'A' + n - 1);
        return res;
    }
};
