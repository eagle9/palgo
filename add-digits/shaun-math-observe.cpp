//Given a non-negative integer num, 
/*
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
那么我们先来观察1到20的所有的树根：

1    1
2    2
3    3
4    4
5    5
6    6
7    7
8    8    
9    9    
10    1
11    2
12    3    
13    4
14    5
15    6
16    7
17    8
18    9
19    1
20    2
*/
//grandyang math idea observation from example simple problems
//runtime 0ms, faster than 100%, mem less than 15%
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        //return (num == 0) ? 0 : (num - 1) % 9 + 1;
        return num % 9;

    }
};
