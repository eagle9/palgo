//Your submission beats 99.40% Submissions!
//http://www.cnblogs.com/grandyang/p/5864323.html
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        if (values.size() <= 2) return true;
        int n = values.size(), sum = 0;
        //其中dp[i]表示从i到end可取的最大钱数
        vector<int> dp(n + 1, 0);
        dp[n - 1] = values[n - 1];
        dp[n - 2] = values[n - 2] + values[n - 1];
        dp[n - 3] = values[n - 3] + values[n - 2];
        for (int i = n - 4; i >= 0; --i) {
            //at i take values[i], opponent takes i+1 (we max remaining at dp[i+2])  or opponent takes i+1 and i+2 (we max remaining dp[i+3])
            int max1 = values[i] + min(dp[i + 2], dp[i + 3]);
            int max2 = values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]);
            dp[i] = max(max1,max2 );
        }
        for (int d : values) {
            sum += d;
        }
        
        //first player max is dp[0], the other max is sum - dp[0]
        return dp[0] > sum - dp[0];
    }
};

/*
这道题是之前那道Coins in a Line的延伸，由于每个硬币的面值不同，所以那道题的数学解法就不行了，这里我们需要使用一种方法叫做极小化极大算法Minimax，这是博弈论中比较经典的一种思想，LeetCode上有一道需要用这种思路解的题Guess Number Higher or Lower II。这道题如果没有接触过相类似的题，感觉还是蛮有难度的。我们需要用DP来解，我们定义一个一维数组dp，其中dp[i]表示从i到end可取的最大钱数，大小比values数组多出一位，若n为values的长度，那么dp[n]先初始化为0。我们是从后往前推，我们想如果是values数组的最后一位，及i = n-1时，此时dp[n-1]应该初始化为values[n-1]，因为拿了肯定比不拿大，钱又没有负面额；那么继续往前推，当i=n-2时，dp[n-2]应该初始化为values[n-2]+values[n-1]，应为最多可以拿两个，所以最大值肯定是两个都拿；当i=n-3时，dp[n-3]应该初始化为values[n-3]+values[n-2]，因为此时还剩三个硬币，你若只拿一个，那么就会给对手留两个，当然不行，所以自己要拿两个，只能给对手留一个，那么到目前位置初始化的步骤就完成了，下面就需要找递推式了：

当我们处在i处时，我们有两种选择，拿一个还是拿两个硬币，我们现在分情况讨论：

1. 当我们只拿一个硬币values[i]时，那么对手有两种选择，拿一个硬币values[i+1]，或者拿两个硬币values[i+1] + values[i+2]
a) 当对手只拿一个硬币values[i+1]时，我们只能从i+2到end之间来取硬币，所以我们能拿到的最大硬币数为dp[i+2]
b) 当对手拿两个硬币values[i+1] + values[i+2]时，我们只能从i+3到end之间来取硬币，所以我们能拿到的最大硬币数为dp[i+3]
由于对手的目的是让我们拿较小的硬币，所以我们只能拿dp[i+2]和dp[i+3]中较小的一个，所以对于我们只拿一个硬币的情况，我们能拿到的最大钱数为values[i] + min(dp[i+2], dp[i+3])

2. 当我们拿两个硬币values[i] + values[i + 1]时，那么对手有两种选择，拿一个硬币values[i+2]，或者拿两个硬币values[i+2] + values[i+3]
a) 当对手只拿一个硬币values[i+2]时，我们只能从i+3到end之间来取硬币，所以我们能拿到的最大硬币数为dp[i+3]
b) 当对手拿两个硬币values[i+2] + values[i+3]时，我们只能从i+4到end之间来取硬币，所以我们能拿到的最大硬币数为dp[i+4]
由于对手的目的是让我们拿较小的硬币，所以我们只能拿dp[i+3]和dp[i+4]中较小的一个，所以对于我们只拿一个硬币的情况，我们能拿到的最大钱数为values[i] + values[i + 1] + min(dp[i+3], dp[i+4])

综上所述，递推式就有了 dp[i] = max(values[i] + min(dp[i+2], dp[i+3]), values[i] + values[i + 1] + min(dp[i+3], dp[i+4]))
这样当我们算出了dp[0]，知道了第一个玩家能取出的最大钱数，我们只需要算出总钱数，然后就能计算出另一个玩家能取出的钱数，二者比较就知道第一个玩家能否赢了
*/
