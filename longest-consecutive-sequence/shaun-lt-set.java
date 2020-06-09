/*
Runtime: 3 ms, faster than 91.51% of Java online submissions for Longest Consecutive Sequence.
Memory Usage: 40 MB, less than 13.80% of Java online submissions for Longest Consecutive Sequence.

lt set idea, check all number for possible start, stretch it
shaun understand
*/
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        //check each number if it can be a start of +1 sequence 
        for (int num : num_set) {
            //num should be start, don't want num-1 in the set
            if (!num_set.contains(num-1)) { //comment out works, but much slower
                int currentNum = num;
                int currentStreak = 1;
                
                //strech the sequence as much as possible
                while (num_set.contains(currentNum+1)) {
                    currentNum++;
                    currentStreak++;
                }
                //update longest
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}
