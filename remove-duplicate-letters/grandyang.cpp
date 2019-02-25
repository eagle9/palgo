/*
grandyang idea1
to understand and write yourself

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Remove Duplicate Letters.
Memory Usage: 8.4 MB, less than 94.29% of C++ online submissions for Remove Duplicate Letters.

*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto a : s) ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
};
