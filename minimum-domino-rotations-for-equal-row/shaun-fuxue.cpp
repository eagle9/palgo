//shaun code and idea leared from https://blog.csdn.net/fuxuemingzhu/article/details/88379160
//runtime 140ms, faster than 19%, mem less than 83%
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        for (int x: A) {
            m[x]++;
        }
        for (int x: B) m[x]++;
        int maxCount = -1, target;
        for (auto kv: m) {
            if (kv.second > maxCount) {
                maxCount = kv.second;
                target = kv.first;
            }
        }
        if (maxCount < A.size()) return -1;
        
        int a_rotations = 0, b_rotations = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == B[i]) {
                if (A[i] == target) continue;
                return -1; //Ai != target
            }else if (A[i] == target) { //Ai != Bi, and Ai == target, Bi != target, rotate to B
                b_rotations++;
            }else if (B[i] == target) { //Ai != Bi, and Bi == target, Ai != target, rotate to A
                a_rotations++;
            }else { //Ai != Bi, none of them == target
                return -1;
            }
        }
        return min(a_rotations, b_rotations);
    }
};
