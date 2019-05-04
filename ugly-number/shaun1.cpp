//first sub TLE, right direction but didn't get details right
class Solution000 {
public:
    bool isUgly(int num) {
        while (num % 2 ==  0) num /= 2;
        if (num == 1) return true;
        while (num % 3 == 0) num /= 3;
        if (num == 1) return true;
        while (num % 5 == 0) num/= 5;
        return num == 1;
    }
};
//checked with jz, 
//runtime 4ms, faster than 100%, mem less than 25%
class Solution {
public:
    bool isUgly(int num) {
        while (num >=2 && num % 2 ==  0) num /= 2;
        while (num >=3 && num % 3 == 0) num /= 3;
        while (num >=5 && num % 5 == 0) num/= 5;
        return num == 1;
    }
};
