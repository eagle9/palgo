//jz 方法二 nim 博弈
//beats 100%, no recursion, much faster, but don't understand
public class Solution {
    public boolean canWin(String s) {
        int[] nim = new int[s.length() + 1];
        boolean[] happen = new boolean[s.length() + 1];
        for (int i = 2; i <= s.length(); i++) {
            for (int j = 0; j < i - j - 1; j++) {
                happen[nim[j] ^ nim[i - j - 2]] = true;
            }
            boolean nimEmpty = true;
            for (int j = 0; j <= s.length(); j++) {
                if (!happen[j] && nimEmpty) {
                    nimEmpty = false;
                    nim[i] = j;
                } else {
                    happen[j] = false;
                }
            }
        }
        int ans = 0;
        int len = 0;
        s = s + "-";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+') {
                len++;
            } else {
                ans = ans ^ nim[len];
                len = 0;
            }
        }
        if (ans == 0) {
            return false;
        } else {
            return true;
        }
    }
}
