//jz dfs, beats 92.60%
class Solution {
    List<String> res = new ArrayList<>();
    int n;
    
    void gen(int nleft, int nright, String cur) {
        if (nleft == n && nright == n) {
            res.add(cur);
            return;
        }
        
        if (nleft < n) {
            gen(nleft + 1, nright, cur + "(");
        }
        
        if (nright < nleft) {
            gen(nleft, nright + 1, cur + ")");
        }
    }
    
    public List<String> generateParenthesis(int nn) {
        n = nn;
        gen(0, 0, "");
        return res;
    }
}
