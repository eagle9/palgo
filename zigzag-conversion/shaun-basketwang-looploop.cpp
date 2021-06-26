//https://www.youtube.com/watch?v=8zXTAn7i5rU
//basket wang loop with loop idea, i have the same idea and found basketwang's is very similar to mine. Just have to iron out the details and building blocks
//cutting main loop, iterate string s from 0 to its len -1
//  1 small loop going down row 0 to row n-1, 
// another small loop going up from row n-2 to 1
// each row with a string
//runtime 8ms, faster than 95%, mem less than 27%
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        vector<string> rows(numRows);
        int i = 0;
        while (i < len) {
            //go down from row 0 to numRows - 1
            for (int idx = 0; idx < numRows && i < len; ++idx) {
                rows[idx].push_back(s[i++]);
            }
            //go up from row numRows - 2 to 0 (to 0 is bug), should to 1, why? 
            // becausenext step will be going down from 0 to n-1
            //for (int idx= numRows-2; idx >=0 && i < len; --idx) {
            for (int idx= numRows-2; idx >=1 && i < len; --idx) {
                rows[idx].push_back(s[i++]);
            }
        }
        string res = "";
        for (string row: rows) {
            res += row;
        }
        return res;
    }    
};   
