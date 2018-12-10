//grandyang java, beats 99%
//not easy to understand this problem, not quite with details
public class Solution {
    public int lengthLongestPath(String input) {
        int res = 0;
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 0);
        //for each line
        for (String s : input.split("\n")) {
            //level is from left to right, according to \t
            int level = s.lastIndexOf("\t") + 1;
            int len = s.substring(level).length();
            if (s.contains(".")) { //file name
                res = Math.max(res, m.get(level) + len);
            } else { //folder name
                //why +len+1????
                //prev level + \n\t +  folder_name
                m.put(level + 1, m.get(level) + len + 1);
            }
        }
        return res;
    }
}
