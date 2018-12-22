public class Solution {
    //grandyang idea1, shaun java code, beats 77%
    public int repeatedStringMatch(String A, String B) {
        int n1 = A.length(), n2 = B.length(), cnt = 1;
        StringBuilder t = new StringBuilder(A);
        while (t.length() < n2) {
            t.append(A);
            ++cnt;
        }
        //now t.length() >= n2
        if (t.indexOf(B) >= 0) return cnt;
        t.append(A);
        return (t.indexOf(B) >= 0)? cnt + 1 : -1;
    }
};
