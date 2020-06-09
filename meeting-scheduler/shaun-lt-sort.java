
/*
Time : O(nlogn), Space : O(m + n) where n is the length of slots1 and m the length of slots2

Runtime: 54 ms, faster than 10.45% of Java online submissions for Meeting Scheduler.
Memory Usage: 71.4 MB, less than 100.00% of Java online submissions for Meeting Scheduler.

lt disucss
*/

class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        
		// Check if input is valid
        if(slots1 == null || slots2 == null || slots1.length == 0 || slots2.length == 0)
            return new ArrayList<>();
        
		// Create common array
        List<int[]> slots = new ArrayList<>();

        // Add slots1 and slots2 to the common schedule
        for(int[] s1 : slots1)
            slots.add(s1);
        for(int[] s2 : slots2)
            slots.add(s2);
        
		// Sort the array in ascending order
        Collections.sort(slots,(a,b)->{   
            return a[0]-b[0];
        });
        
        for(int i = 0; i < slots.size() - 1;i++){
            
            int[] next = slots.get(i+1);
            int[] curr = slots.get(i);
            
			// Check if there is a collision and if that collision if greater or equal then duration 
            if(curr[1] > next[0] &&  next[0] + duration <= curr[1] && next[0] + duration <= next[1]) {
                //start next[0], end either curr[1] or next[1]
                return new ArrayList<>(Arrays.asList(next[0],next[0] + duration));
            }
                
        }
        
		// Return empty list if there is no common free time
        return new ArrayList<>();
        
    }
}
