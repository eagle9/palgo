/*
 100 * 100
=10000
9 * 9 = 81, product len = m + n
    1 0
    8 9  <- num2, i 
    7 6  <- num1, j
-------     j*i  store at vals' p1 p2
    5 4     00 ->01
  4 8       01 ->12
  6 3       10 ->12
5 6         11 ->23
-------
6 7 6 4

grandyang idea with string char <-> int conversion and array to store big integers. 
shaun same idea of using array. use example to figure out the details. 
break down into m*n single digit multiplications
4ms, faster than 96%, mem less than 42%
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        
        //int to char, val + '0'
        //char to int , c - '0'
        int m = num1.size(), n = num2.size();
        vector<int> vals(m + n);
        //from tail char to head
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                //where to store mul? 
                int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        //convert vector<int> back to string
        string res = "";
        for (int val : vals) {
            if (val == 0 && res.empty()) continue; //leading 0
            res.push_back(val + '0');
            //if (!res.empty() || val != 0) res.push_back(val + '0');
        }
        return res.empty() ? "0" : res;
    }
};
