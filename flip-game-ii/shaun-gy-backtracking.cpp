//grandyang backtracking and minimax
//runtime 428ms, faster than 10%, mem less than 8.5%
class Solution1 {
public:
    bool canWin(string s) {
        //try all possible flips ++ --> --
        for (int i = 1; i < s.size(); ++i) {
            // 0  i-2   i-1 i       n-1
            //0 .. i-2, substr(0,i-2-0+1) 
            if (s[i] == '+' && s[i - 1] == '+') {
                
                string flipped = s.substr(0, i - 1) + "--" + s.substr(i + 1);
                //now with flipped, it's opponent's turn to play
                //same problem, deeper state, if he can not win, then i win
                if (!canWin(flipped)) return true;
                //flipped is a copy, no need for backtracking s
            }
        }
        
        //tried all possibilities, no way for me to win, 
        return false;
    }
};

//shaun modified for faster speed
//runtime 176ms, faster than 35%, mem less than 28%
class Solution2 {
public:
    bool canWin(string s) {
        //try all possible flips ++ --> --
        for (int i = 1; i < s.size(); ++i) {
            // 0  i-2   i-1 i       n-1
            //0 .. i-2, substr(0,i-2-0+1) 
            if (s[i - 1] == '+' && s[i] == '+') {
                s[i-1] = '-';
                s[i] = '-';
                //now with flipped, it's opponent's turn to play
                //same problem, deeper state, if he can not win, then i win
                if (!canWin(s)) return true;
                //backtracking s
                s[i-1] = '+';
                s[i] = '+';
            }
        }
        
        //tried all possibilities, no way for me to win, 
        return false;
    }
};

//wrong answer
class Solution {
public:
    bool canWin(string s) {
        return helper(s);
    }
    bool helper(string& s) {
        //try all possible flips ++ --> --
        for (int i = 1; i < s.size(); ++i) {
            // 0  i-2   i-1 i       n-1
            //0 .. i-2, substr(0,i-2-0+1) 
            if (s[i - 1] == '+' && s[i] == '+') {
                s[i-1] = '-';
                s[i] = '-';
                //now with flipped, it's opponent's turn to play
                //same problem, deeper state, if he can not win, then i win
                if (!helper(s)) return true;
                //backtracking s
                s[i-1] = '+';
                s[i] = '+';
            }
        }
        
        //tried all possibilities, no way for me to win, 
        return false;
    }
};
