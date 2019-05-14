/*
Runtime: 89 ms, faster than 68.75% of Java online submissions for Odd Even Jump.
Memory Usage: 34.5 MB, less than 21.69% of Java online submissions for Odd Even Jump.
lt treemap

Complexity Analysis

Time Complexity: O(NlogN), where N is the length of A.

Space Complexity: O(N) 
*/
class Solution {
    public int oddEvenJumps(int[] A) {
        int N = A.length;
        if (N <= 1) return N;
		//odd[i] --can reach end starting from i up
        boolean[] odd = new boolean[N];
		//even[i] --can reach end starting from i down
        boolean[] even = new boolean[N];

		//tabulate from tail
        odd[N-1] = even[N-1] = true;
		//vals --- map from value to min index of such value so far
        TreeMap<Integer, Integer> vals = new TreeMap();
        vals.put(A[N-1], N-1);

        for (int i = N-2; i >= 0; --i) {
            int v = A[i];
            if (vals.containsKey(v)) {
                odd[i] = even[vals.get(v)];
                even[i] = odd[vals.get(v)];
            } else {
                Integer lower = vals.lowerKey(v);
                Integer higher = vals.higherKey(v);

                if (lower != null)
                    even[i] = odd[vals.get(lower)];
                if (higher != null) {
                    odd[i] = even[vals.get(higher)];
                }
            }
            vals.put(v, i);
        }

        int ans = 0;
        for (boolean b: odd)
            if (b) ans++;
        return ans;
    }
}
