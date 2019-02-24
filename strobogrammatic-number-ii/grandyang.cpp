/*
Runtime: 56 ms, faster than 88.33% of C++ online submissions for Strobogrammatic Number II.
Memory Usage: 25.7 MB, less than 100.00% of C++ online submissions for Strobogrammatic Number II.

grandyang recursion
how to come up with this idea, make sure brute force is not advised. find the solutions for smaller problem manually, and find rules to attack larger problem

*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    //m is length of the number, n is constant
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n), res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0"); //0...0 can be wrapped inside, this is key
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};
