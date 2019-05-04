//shaun code upon hint of merge 3 sorted array idea, 
//accepted after fixing m2 = res[i2] ----> m2 = res[i2]*2
//if you test with a simple case, you will get the details right
//runtime 8ms, faster than 96%, mem less than 44%
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        int i = 1;
        vector<int> res = {1};
        while (true) {
            if (i == n) return res.back();
            int m2 = res[i2]*2, m3 = res[i3]*3, m5 = res[i5]*5;
            int min1 = min(m2, min(m3, m5));
            if (min1 == m2) i2++;
            if (min1 == m3) i3++;
            if (min1 == m5) i5++;
            res.push_back(min1);
            i++;
        }
        
    }
};
