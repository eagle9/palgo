/*
本质其实就是在n个数字中取出k个，那么就跟之前的那道Combinations一样，我们可以借鉴那道题的解法，那么思路是，如果总共要取num个，我们在小时集合里取i个，算出和，然后在分钟集合里去num-i个求和，如果两个都符合题意，那么加入结果中即可
grandyang idea, beats 79%, break down into hour and min combinations, refer to combinations solution
*/
class Solution {

    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<>();
        int [] hour= {8, 4, 2, 1};
        int [] minute = {32, 16, 8, 4, 2, 1};
        for (int i = 0; i <= num; ++i) {
            List<Integer> hours = generate(hour, i);
            List<Integer> minutes = generate(minute, num - i);
            //combine hour and minute
            for (Integer h : hours) {
                //A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
                if (h > 11) continue;
                for (Integer m : minutes) {
                    if (m > 59) continue;
                    res.add(String.valueOf(h) + (m < 10 ? ":0" : ":") + String.valueOf(m));
                }
            }
        }
        return res;
    }
    private List<Integer> generate(int [] nums, int cnt) {
        List<Integer> res = new ArrayList<>();
        helper(nums, cnt, 0, 0, res);
        return res;
    }
    private void helper(int [] nums, int cnt, int start, int comb, List<Integer> res) {
        if (cnt == 0) {
            res.add(comb);
            return;
        }
        for (int i = start; i < nums.length; ++i) {
            helper(nums, cnt - 1, i + 1, comb + nums[i], res);
        }
    }
};
