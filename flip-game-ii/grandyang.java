//grandyang idea, shaun java code, recursion is easy to give a solution. 
//runtime 107ms, faster than 31%
class Solution {
    public boolean canWin(String s) {
        char [] chars = s.toCharArray();
        for (int i = 1; i < chars.length; i++) {
            //try all possible flips
            if (chars[i] == '+' && chars[i-1] == '+') {
                String flipped = s.substring(0,i-1) + "--" + s.substring(i+1);
                //opponent can not win, then we can find a way to win
                if (!canWin(flipped)) return true;

            }
        }
        //tried all flips and we can not win at all
        return false;

    }
}
/*
grandyang
class Solution {
public:
    bool canWin(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
                return true;
            }
        }
        return false;
    }
};
*/
