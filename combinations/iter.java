//beats 100.00%
//how to understand this, just present a simple example and how you list all the combinations
public class Solution {
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cd = new ArrayList<>();
        for (int i = 1; i <=k; i++) {
            cd.add(i);
        }
        //this is the first combination, makes sense
        res.add(new ArrayList<Integer>(cd));
        int i = k-1; //from k-1 to 0
        while (i >= 0) {
            if (cd.get(i) <= n - k + i) {
                cd.set(i, cd.get(i) + 1);
            
                for (int j = i+1; j <= k-1; j++) {
                    cd.set(j, cd.get(j-1) + 1);
                }
                res.add(new ArrayList<Integer>(cd));
                i = k - 1;
            }else {
                i--;
            }
        }
        return res;
    }
}
/*
1 2 3 4
12
13
14
23
24
34
C(4,2) = 4*3/2 = 6
*/
