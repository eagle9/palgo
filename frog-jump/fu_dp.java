/* Dynamic programming, HashMap<Integer, Set<Integer>>
//dp with hashmap, the essence is recurrence, figure out larger index from lower index
//https://www.youtube.com/watch?v=-FBfrVz841k
 * time complexity: O(n^2), space complexity O(n^2) */
//runtime 77ms, faster than 39%, 

public class Solution {
    public boolean canCross(int[] stones) {
        //corner case
        if (stones.length == 0) {
            return false;
        }
        //stone index ---> number of steps from previous stone
        Map<Integer, Set<Integer>> hm = new HashMap<>();
        //init the map/table
        for (int i = 0; i < stones.length; i++) {
            hm.put(stones[i], new HashSet<>());
        }
        // stone 0
        hm.get(stones[0]).add(0);
        //stone 1 ===? must be 1, otherwise false
        
        //from stone 0, try to jump to next stone
        for (int i = 0; i < stones.length; i++) {
            for (int step : hm.get(stones[i])) {
                //next step's valid value range
                for (int nextStep = step - 1; nextStep <= step + 1; nextStep++) {
                    //must move forward ==> . nextStep > 0
                    if (nextStep > 0 && hm.containsKey(stones[i] + nextStep)) {
                        hm.get(stones[i] + nextStep).add(nextStep);
                    }
                }
            }
        }
        // if there exist a jump step at the last stone, then it is able to cross river
        return !hm.get(stones[stones.length - 1]).isEmpty();
    }
}
