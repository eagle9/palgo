//grandyang idea1, shaun java code, beats 94%
public class Solution {
    public int findRadius(int [] houses, int [] heaters) {
        int n = heaters.length, j = 0, res = 0;
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        for (int i = 0; i < houses.length; ++i) {
            int cur = houses[i];
            //for each house, iterate all heaters, find higher rank heater that minizes the diff
            while (j < n - 1 && Math.abs(heaters[j + 1] - cur) <= Math.abs(heaters[j] - cur)) {
                ++j;
            }
            //heater j  minimize diff btw houses[i]
            res = Math.max(res, Math.abs(heaters[j] - cur));
        }
        return res;
    }
};
