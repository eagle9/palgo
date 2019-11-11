//check with either A[0] or B[0], naturally write a function
//shaun code with lt idea,
//runtime 120ms, faster than 81%, mem less than 100%
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = check(A[0], A, B);
        
        int b = check(B[0], A, B);
        if (a == -1) return b;
        if (b == -1) return a;
        return min(a,b);
    }
private:
    //
    int check(int x, vector<int>& A, vector<int>& B) {
        int a_rotations = 0, b_rotations = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != x && B[i] != x) return -1;
            //now Ai == x or Bi == x
            /*
            //coding like this works using !=
            if (A[i] != x) a_rotations++;
            if (B[i] != x) b_rotations++;
            */
            if (A[i] == B[i]) continue;
            if (A[i] == x && B[i] != x) b_rotations++;
            if (B[i] == x && A[i] != x) a_rotations++;
            
        }
        return min(a_rotations, b_rotations);
    }
};
