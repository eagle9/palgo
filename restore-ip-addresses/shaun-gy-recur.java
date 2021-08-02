/*
gy recur idea, shaun understood
k来表示当前还需要分的段数，如果k = 0，则表示三个点已经加入完成，四段已经形成，若这时字符串刚好为空，则将当前分好的结果保存。若k != 0, 则对于每一段，我们分别用一位，两位，三位来尝试，分别判断其合不合法，如果合法，则调用递归继续分剩下的字符串，最终和求出所有合法组合
*/
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        restore(s, 4, "", res);
        return res;
    }
    void restore(String s, int k, String out, List<String> res) {
        if (k == 0) {
            if (s.isEmpty()) res.add(out);
        }
        else {
            //try the first 1 to 3 digits
            for (int i = 1; i <= 3; ++i) {
                //if the first section good, the recur to smaller problem
                if (i <= s.length() && isValid(s.substring(0, i))) {
                    //last section
                    if (k == 1) restore(s.substring(i), k - 1, out + s.substring(0, i), res);
                    //not last section
                    else restore(s.substring(i), k - 1, out + s.substring(0, i) + ".", res);
                }
            }
        }
    }
    boolean isValid(String s) {
        if (s.length() == 0 || s.length() > 3 || (s.length() > 1 && s.charAt(0) == '0')) return false;
        int res = Integer.valueOf(s);
        return res <= 255 && res >= 0;
    }
}

