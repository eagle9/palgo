//shaun has the idea to do 2 reverse
//grandyang the same idea, look for space or end, track recent left, reverse it
//then reverse entire
//runtime 56ms, faster than 95%, mem less than 91%
class Solution {
public:
    void reverseWords(vector<char>& str) {
        int left = 0, n = str.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || str[i] == ' ') {
                reverse(str, left, i - 1);
                left = i + 1;
            }
        }
        reverse(str, 0, n - 1);
    }
    void reverse(vector<char>& str, int left, int right) {
        while (left < right) {
            char t = str[left];
            str[left] = str[right];
            str[right] = t;
            ++left; --right;
        }
    }
};
