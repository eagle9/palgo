/*
Runtime: 4 ms, faster than 87.59% of Java online submissions for Meeting Scheduler.
Memory Usage: 49.2 MB, less than 100.00% of Java online submissions for Meeting Scheduler.
based on lt discuss c++
*/

class Solution {
    class Slot {
        int time;
        boolean flag;
        public Slot(int time, boolean flag) {
            this.time = time;
            this.flag = flag;
        }
    }
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        List<Slot> slots = new ArrayList<>();
        for (int [] s: slots1) {
            if (s[1] - s[0] >= duration) {
                slots.add(new Slot(s[0], true));
                slots.add(new Slot(s[1], false));
            }
        }
        for (int [] s: slots2) {
            if (s[1] - s[0] >= duration) {
                slots.add(new Slot(s[0], true));
                slots.add(new Slot(s[1], false));
            }
        }
        Collections.sort(slots, (a,b) -> a.time - b.time);
        int open = 0, start = 0;
        for (Slot s: slots) {
            if (s.flag) {
                open++;
            }else {
                if (open == 2) {
                    int d = s.time - start;
                    if (d >= duration) return Arrays.asList(start,start+duration);
                }
                open--;
            }
            
            if (open == 2) start = s.time;
        }
                  
        return new ArrayList<>();
    }
}



