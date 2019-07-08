/*shaun try dfs with greedy and pruning, first sub wrong answer!
positives: come up with most points of hua's dfs
wrong points:
1)  not clear how to update ans, take min
2)  loop condition to recursion 
3) greedy, sort descending, used largest number of coins[start] first, down to 0, make sure 
after fixed the two points,  accepted, runtime 8ms, faster than 99.96%
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        /*
        [5,2,1], 11, 0, 
        /2x5       \1x5       0x5
    [2,1], 1,2   
    
    */
        int ans = INT_MAX;
        //sort coins descending order, being greedy to find answer faster, able to pruning branches quicker
        sort(coins.begin(), coins.end(), greater<int>()); //greater in front
        //sort(coins.rbegin(), coins.rend());
        helper(coins, 0,amount, 0, ans);
        
        return ans == INT_MAX? -1: ans;
    }
    
private:
    //amount to make, number of used coins, start index of coin to use (not erase coin from coins vector)
    void helper(vector<int>& coins, int start, int amount, int used,  int& ans) {
        
        if (amount == 0) {
            //done make amount
            //ans = used;   //first sub, wrong answer and TLE, not clear about how to update answer
            //ans = used < ans? used: ans; --> okay too
            ans = min(ans, used);
            return;
        }
        //if (used >= ans) return; //prune branches, no need to go down this branches already used more coins
        
        if (start == coins.size()) return; //all coins used up
        //try coins[start] 0 to i times   i*c <= amount
        const int coin = coins[start]; //const not required, but better declaration this way
        
        // the following TLE, put i+used < ans to loop condition
        for (int i = amount/coin; i>=0 && i + used < ans; --i) {
            //if (i + used < ans) ----> bug 1, put this into for loop end condition
                helper(coins,start+1,amount-i*coin, used+i,ans);
        }
        
        
    }
};


