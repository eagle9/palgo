//shaun own idea and code, accepted after 1 bug fix res[i] --> res[i-1]
//runtime 4ms, faster than 98%, mem less than 88%
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                res[i-1] = "FizzBuzz"; //bug 1, should use i-1 for index
                continue;
            }
            if (i % 3 == 0) {
                res[i-1] = "Fizz";
                continue;
            }
            if (i % 5 == 0) {
                res[i-1] = "Buzz";
                continue;
            }
            res[i-1] = to_string(i);
        }
        return res;
    }
};
