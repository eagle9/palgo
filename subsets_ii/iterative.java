//https://www.sigmainfy.com/blog/leetcode-subset-i-and-ii.html
//no recursive, Your submission beats 100.00% Submissions!
/*Another different angle to remove duplicates is to treat the continues duplicates number S[i] which appears t times as a whole, and this whole thing have 1 + t choices for us, to put 0..t of them into the subsets. This implementation could be integrated into the 3rd approach fro Subsets I discussed previously and the following iterative implementations is accepted by LeetCode OJ to pass both the Subsets I and II problems:
*/
//coult not get java to work, don't know why, c++ vector<vector<int> > vv(1) is hard to translate
public class Solution {
    public List<List<Integer> > subsetsWithDup(int[] S) {
        Arrays.sort(S);
        List<List<Integer>> vv = new ArrayList<Lis<Integer>>(1);
        int i= 0, cnt = 0;
        int n = S.length;
        while (i < n) {
            cnt = 1;
            while (i + cnt < n && S[i] == S[i + cnt]) cnt++;
            for (int k = vv.size() - 1; k >= 0; k--) {
                List<Integer> tmp = vv[k];
                for (int j = 1; j <= cnt; ++j) {
                    tmp.add(S[i]);
                    vv.add(tmp);
                }
            }
            i += cnt;
        }
        return vv;
    }
};
