//https://blog.csdn.net/koala_tree/article/details/80236297 
//runtime 4ms, faster than 98%, mem less than 59%
class Solution2 {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;

        int count = 0;
        while(n > 1){
            if(n % 2 == 0)
                n = n/2;
            else{
                if((n+1)%4 == 0 && (n-1 != 2))
                    n++;
                else
                    n--;
            }
            count++;
        }

        return count;
    }
};

//runtime 8ms, faster than 50%, mem less than 57%
//grandyang simple recursion
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1 + integerReplacement(n / 2);
        else {
            long long t = n;
            return 2 + min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }
    }
}; 

