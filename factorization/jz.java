//jz dfs, helper2 beats 98.40%
// helper1 Time Limit Exceeded
//from helper1 to helper2
// idea ---> https://www.cnblogs.com/lz87/p/7494025.html
public class Solution {
    /**
     * @param n an integer
     * @return a list of combination
     */
    public List<List<Integer>> getFactors(int n) {
        // write your code here
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        helper2(result, new ArrayList<Integer>(), n, 2);
        return result;
    }
    
    private void helper1(List<List<Integer>> results, List<Integer> list, int n, int startFactor) {
        if(n == 1) {
            if(list.size() > 1) {
                results.add(new ArrayList<Integer>(list));
            }
            return;
        }
        for(int i = startFactor; i <= n; i++) {
            if(n % i == 0) {
                list.add(i);
                helper1(results, list, n / i, i);
                list.remove(list.size() - 1);
            }
        }
    }

    public void helper2(List<List<Integer>> result, List<Integer> item, int n, int start) {
        if (n <= 1) {
            if (item.size() > 1) {
                result.add(new ArrayList<Integer>(item));
            }
            return;
        }
    
        for (int i = start; i <= Math.sqrt(n); ++i) {
            if (n % i == 0) {
                item.add(i);
                helper2(result, item, n / i, i);
                item.remove(item.size()-1);
            }
        } 
        if (n >= start) {
            item.add(n);
            helper2(result, item, 1, n);
            item.remove(item.size() - 1);
        }
    }
}//jz dfs, helper2 beats 98.40%
// helper1 Time Limit Exceeded
//from helper1 to helper2
// idea ---> https://www.cnblogs.com/lz87/p/7494025.html
public class Solution {
    /**
     * @param n an integer
     * @return a list of combination
     */
    public List<List<Integer>> getFactors(int n) {
        // write your code here
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        helper2(result, new ArrayList<Integer>(), n, 2);
        return result;
    }
    
    private void helper1(List<List<Integer>> results, List<Integer> list, int n, int startFactor) {
        if(n == 1) {
            if(list.size() > 1) {
                results.add(new ArrayList<Integer>(list));
            }
            return;
        }
        for(int i = startFactor; i <= n; i++) {
            if(n % i == 0) {
                list.add(i);
                helper1(results, list, n / i, i);
                list.remove(list.size() - 1);
            }
        }
    }

    public void helper2(List<List<Integer>> result, List<Integer> item, int n, int start) {
        if (n <= 1) {
            if (item.size() > 1) {
                result.add(new ArrayList<Integer>(item));
            }
            return;
        }
    
        for (int i = start; i <= Math.sqrt(n); ++i) {
            if (n % i == 0) {
                item.add(i);
                helper2(result, item, n / i, i);
                item.remove(item.size()-1);
            }
        } 
        if (n >= start) {
            item.add(n);
            helper2(result, item, 1, n);
            item.remove(item.size() - 1);
        }
    }
}
