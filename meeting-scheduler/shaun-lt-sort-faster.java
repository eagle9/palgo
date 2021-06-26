
/*
Time : O(nlogn), Space : O(m + n) where n is the length of slots1 and m the length of slots2


Runtime: 6 ms, faster than 80.22% of Java online submissions for Meeting Scheduler.
Memory Usage: 66.1 MB, less than 100.00% of Java online submissions for Meeting Scheduler.

faster when skip slots whose length is < duration
*/

class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        
		// Check if input is valid
        if(slots1 == null || slots2 == null || slots1.length == 0 || slots2.length == 0)
            return new ArrayList<>();
        
		// Create common array
        List<int[]> common = new ArrayList<>();

        // Add slots1 and slots2 to the common schedule
        for(int[] s : slots1) {
            if (s[1] - s[0] >= duration)
                common.add(s);
        }
        for(int[] s : slots2) {
            if (s[1] - s[0] >= duration)
                common.add(s);
        }
        
		// Sort the array in ascending order
        Collections.sort(common,(int[]a,int[]b)->{   
            return a[0]-b[0];
        });
        
        for(int i = 0; i < common.size() - 1;i++){
            
            int[] next = common.get(i+1);
            int[] curr = common.get(i);
            
			// Check if there is a collision and if that collision if greater or equal then duration 
            if(curr[1] > next[0] && curr[1] - next[0] >= duration && next[0] + duration <= next[1])
                return new ArrayList<>(Arrays.asList(next[0],next[0] + duration));
        }
        
		// Return empty list if there is no common free time
        return new ArrayList<>();
        
    }
}
