// hua recursion with memo and minimax
// runtime 16ms, faster than 94%, mem less than 80%
//  player 1 take a number, the problem boils down to a similar problem, with different 
// parameters, first parameter is the set of numbers (fewer numbers not yet used), 
// second parameter is the number range max number M, 
// 3rd parameter is the target number to reach or over
class Solution {
public:
    //number 1 .. M 
    bool canIWin(int M, int T) {
        const int sum = M * (M + 1) / 2;
        if (sum < T) return false;
        if (T <= 0) return true;
      
        //draw number from 1  to M, 1<<M combinations     
        m_ = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }
private:
    vector<char> m_; // 0: unknown, 1: won, -1: lost
    // choose number 1 to M, target T
    bool canIWin(int M, int T, int state) {
        
        //previous player took a number >= T, hence T-number <= 0
        //previous player win, so this player lose
        if (T <= 0) return false;
        
        if (m_[state]) return m_[state] == 1;
        
        for (int i = 0; i < M; ++i) {
            //choose ith number,
            // 0th  1st 2nd 3rd 4th   (M-1)th
            // 1     2                  M
            if (state & (1 << i)) continue; // ith number used, skip       
            // The next player can not win, current player wins
            //ith number(i+1) not used, use it, new target = T - (i+1)
            if (!canIWin(M, T - (i + 1), state | (1 << i))) 
                return m_[state] = 1;
        }
    // Current player no way to win, so he loses
    m_[state] = -1;
    return false;
 }
};

