//jz c++, beats 75%
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* instance;
    static Solution* getInstance() {
        if (instance == NULL) {
            instance = new Solution();
        }
        return instance;
    }
};

Solution* Solution::instance = NULL;
int main() {
    Solution *a = Solution().getInstance();
    Solution *b = Solution().getInstance();
    cout << "a == b" << (a == b) << endl;
}
