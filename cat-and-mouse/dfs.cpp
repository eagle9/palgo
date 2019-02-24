/*
Runtime: 36 ms, faster than 53.85% of C++ online submissions for Cat and Mouse.
Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Cat and Mouse.
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

