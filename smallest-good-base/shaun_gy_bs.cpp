//grandyang idea, runtime 4ms, faster than 100%, mem less than 100%, shaun understood
class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n); //string to long
        //min base is 2,  max base === ?     m is the number of digits
        for (int m = log(num + 1) / log(2); m >= 2; --m) {
            //base min is 2, base max is base^(m-1) = num
            long left = 2, right = pow(num, 1.0 / (m - 1)) + 1;
            while (left +1 < right) {
                
                long mid = left + (right - left) / 2;
                
                long sum  = f(mid,m); 
                if (sum == num) return to_string(mid);
                else if (sum < num) left = mid; //try larger base
                else right = mid; //try smaller base
            }
            if (f(left,m) == num) return to_string(left);
            //if (f(right,m) == num) return to_string(right);
        }
        //no small base found
        return to_string(num - 1);
    }
private:
    //try mid as base sum = 1 + mid + mid^2 + mid^3 +... mid^(m-1)
    // =  1+ base*(1+ base* (1 + base*))
    long f(long base, int m) {
        long sum = 0;
        for (int j = 0; j < m; ++j) {
            sum = sum * base + 1;
        }
        return sum;
    }
};


/*
n = 1 + k + k^2 + k^3 + ... + k^(m-1) > k^(m-1)

k < n^(1 / (m-1))
   pow(n, 1/(m-1) + 1

*/
