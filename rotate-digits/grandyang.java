//grandyang c++, beats 41%
public class Solution {

    public int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (check(i)) ++res;
        }
        return res;
    }
    private bool check(int k) {
        char [] chars = String.valueOf(k).toCharArray();
        boolean flag = false;
        for (char c : chars) {
            //rotate 180 degrees, upside down, no longer valid digit
            if (c == '3' || c == '4' || c == '7') return false;
            //rotate 180, becomes another digit
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;
            //other digits, 1, 8 rotate 180 degres, becomes itself, okay
        }
        //flag must be turned to true to return true
        return flag;
    }
};
