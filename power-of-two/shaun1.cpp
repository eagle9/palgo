//shuan own idea and code, runtime error
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        //while (n > 0) {  //accepted
        while (n) // runtime error
            if (n&1) count++;
            //count += n & 1;
            n >>=1;
        }
        return count ==1;
    }
};

//grandyang idea, diff is the n>0 while condition
//runtime 0ms, faster than 100%, mem less than 16%
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    } 
};

