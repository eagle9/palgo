//grandyang idea2, beats 51%
public class Solution {
    public int findRadius(int [] houses, int [] heaters) {
        int res = 0, n = heaters.length;
        Arrays.sort(heaters);
        for (int house : houses) {
            int left = 0, right = n;
            //找到第一个大于等于当前house位置的heater
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                //heaters[mid] >= house
                else right = mid;
            }
            //left == right, >= house
            //right outbound
            int dist1 = (right == n) ? Integer.MAX_VALUE : heaters[right] - house;
            //leftside outbound
            int dist2 = (right == 0) ? Integer.MAX_VALUE : house - heaters[right - 1];
            res = Math.max(res, Math.min(dist1, dist2));
        }
        return res;
    }
};
