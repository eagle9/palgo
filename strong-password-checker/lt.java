/*
https://leetcode.com/problems/strong-password-checker/discuss/91003/on-java-solution-by-analyzing-changes-allowed-to-fix-each-problem
Runtime: 2 ms, faster than 100.00% of Java online submissions for Strong Password Checker.
Memory Usage: 36.6 MB, less than 28.57% of Java online submissions for Strong Password Checker.

by fun4leetcode
pure string problem with many cases and problem understanding
*/
class Solution {
    public int strongPasswordChecker(String s) {
        int res = 0, a = 1, A = 1, d = 1;
        char[] carr = s.toCharArray();
        int[] arr = new int[carr.length];

        for (int i = 0; i < arr.length;) {
            if (Character.isLowerCase(carr[i])) a = 0;
            if (Character.isUpperCase(carr[i])) A = 0;
            if (Character.isDigit(carr[i])) d = 0;

            int j = i;
            while (i < carr.length && carr[i] == carr[j]) i++;
            arr[j] = i - j;
        }

        int total_missing = (a + A + d);

        if (arr.length < 6) {
            res += total_missing + Math.max(0, 6 - (arr.length + total_missing));

        } else {
            int over_len = Math.max(arr.length - 20, 0), left_over = 0;
            res += over_len;

            for (int k = 1; k < 3; k++) {
                for (int i = 0; i < arr.length && over_len > 0; i++) {
                    if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue;
                    arr[i] -= Math.min(over_len, k);
                    over_len -= k;
                }
            }

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= 3 && over_len > 0) {
                    int need = arr[i] - 2;
                    arr[i] -= over_len;
                    over_len -= need;
                }

                if (arr[i] >= 3) left_over += arr[i] / 3;
            }

            res += Math.max(total_missing, left_over);
        }

        return res;
    }
}
