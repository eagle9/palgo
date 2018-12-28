//jz idea, shaun understand and commented,  beats 61%
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> group;
        char[] c = S.toCharArray();
        int start = 0, end = 0;
        while (end < c.length - 1) {  //we want c at end+1, so <, not <=
            //c end followed by the same char
            if (c[end] == c[end + 1]) {
                end++;
            } else { // c end followed by different char
                //found a large group, len >=3
                if (end - start >= 2) {
                    group = new ArrayList<>();
                    group.add(start);
                    group.add(end);
                    res.add(group);
                }
                //reset start and end after finding a large group
                start = end + 1;
                end = start;
            }
        }
        //end == c.length-1 now, no char at end+1
        //so test large group one more time
        if (end - start >= 2) {
            group = new ArrayList<>();
            group.add(start);
            group.add(end);
            res.add(group);
        }
        return res;
    }
}
