/*
Complexity Analysis
Time Complexity: O(NlogN), where N is the length of A.
Space Complexity: O(N) 
*/
//lt dp with treemap, shaun modified according to hua dp ordered_map idea
//runtime 61ms, faster than 75%, mem less than 99%
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
            
            //Integer lower = vals.lowerKey(A[i]); // lower <A[i] but max in the map, Ai to Aj down jump
            Integer lower = vals.floorKey(A[i]); // lower <=A[i] but max in the map, Ai to Aj down jump
            if (lower != null) {
                int j = vals.get(lower);
                even[i] = odd[j]; //down jump from i ---> jump jump from j
            }
            
            //Integer higher = vals.higherKey(A[i]); // higher > A[i] but min in the map, Ai to Aj up jump
            Integer higher = vals.ceilingKey(A[i]); // higher >= A[i] but min in the map, Ai to Aj up jump
            if (higher != null) {
                int j = vals.get(higher);
                odd[i] = even[j]; //up jump from i ---> down jump from j
            }
            
            vals.put(A[i], i); // A[i] to its min index so far
        }

        int ans = 0;
        for (int i  = 0; i < N; ++i) {
            if (odd[i]) ans++;
        }
            
        return ans;
    }
}
