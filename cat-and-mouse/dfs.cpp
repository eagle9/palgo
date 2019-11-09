/*
Runtime: 32 ms, faster than 70%, mem less than 100%
这道题大意是讲有一个无向图，老鼠从1出发，猫从2出发，老鼠先走。老鼠走到0的洞就老鼠胜，猫走到和老鼠相同的位置就猫胜出，如果猫和老鼠走到相同的位置，则和局。猫不能走进0的洞。现在给出这个图，问最优策略下是什么结果。

这题是一道图论题。但其实就是一道双方最优策略题，这种最优策略题最先想到的就是动态规划加记忆化搜索。但是这题困难的地方在于居然有和局这种东西存在。。。。开始的时候，我是想用vis数组保存一下，让这个节点被访问的时候设为1，然后再次访问就返回0，结果发现这个算法有实质上的错误。后来看了别人的博客，发现他们是用一个变量记录当前游戏轮数（dfs深度），然后轮数达到n+1时游戏还没结束说明有重复状态，就和局（n是点的个数）。（还看了一个用python的，也是像我第一次一样保存访问状态的，结果把代码输进去通不过。。。。）

这个用深度判重和剪枝这个思路真的是非常妙，感觉自己还是挺菜的，下面给出实现代码
————————————————
版权声明：本文为CSDN博主「dicecaster」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/diceroller/article/details/83104950
https://blog.csdn.net/diceroller/article/details/83104950
*/
class Solution {
public:
    int dp[51][51][52];
    int vis[51][51][52];
    int s;
    int catMouseGame(vector<vector<int>>& graph) {
        int ans;
        s = graph.size();
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        ans = dfs(2, 1, graph, 0);
        if(ans==1)
            ans=2;
        else if(ans==-1)
            ans=1;
        return ans;
 
    }
 
    int dfs(int cat, int mouse, vector<vector<int>>& graph, int t)
    {
        int temp,i,ans;
        int order = t % 2;
        if(t>=s+1)
        {
            vis[cat][mouse][t]=1;
            return 0;
        }
        if(vis[cat][mouse][t]==1)
            return dp[cat][mouse][t];
        if(cat==mouse)
            return 1;
        if(mouse==0)
            return -1;
        if(order)//cat move
        {
            ans = -2;
            for(i=0;i<graph[cat].size();i++)
            {
                temp = graph[cat][i];
                if(temp == 0)
                    continue;
                dp[temp][mouse][t+1] = dfs(temp, mouse, graph, t+1);
                if(dp[temp][mouse][t+1]==1)
                {
                    ans = 1;
                    break;
                }
                ans = max(ans,dp[temp][mouse][t+1]);
            }
        }
        else
        {
            ans = 2;
            for(i=0;i<graph[mouse].size();i++)
            {
                temp = graph[mouse][i];
                dp[cat][temp][t+1]=dfs(cat,temp, graph, t+1);
                if(dp[cat][temp][t+1]==-1)
                {
                    ans = -1;
                    break;
                }
                ans = min(ans,dp[cat][temp][t+1]);
 
            }
 
        }
        vis[cat][mouse][t]=1;
        //cout<<cat<<mouse<<order<<" "<<t<<" "<<ans<<endl;
        return ans;
    }
};


