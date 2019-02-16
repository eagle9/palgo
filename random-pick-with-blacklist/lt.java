/*
lt binary search
Runtime: 122 ms, faster than 83.00% of Java online submissions for Random Pick with Blacklist.
Memory Usage: 60.1 MB, less than 100.00% of Java online submissions for Random Pick with Blacklist.



*/
class Solution {

    int n;
    int[] b;
    Random r;

    public Solution(int N, int[] blacklist) {
        n = N;
        Arrays.sort(blacklist);
        b = blacklist;
        r = new Random();
    }

    public int pick() {
        int k = r.nextInt(n - b.length);
        int lo = 0;
		int hi = b.length - 1;

		while (lo < hi) {
			int i = (lo + hi + 1) / 2;
			if (b[i] - i > k) hi = i - 1;
			else lo = i;
		}
		return lo == hi && b[lo] - lo <= k ? k + lo + 1 : k;
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
