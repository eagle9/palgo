//beats 98.60%
//https://leetcode.com/problems/combinations/discuss/27227/fast-and-non-recursive-solution-in-c
class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        
        for (int i = 1; i <= k; i++){
            combination.push_back(i);
        }
    
        combinations.push_back(combination);
    
        int i = k - 1;
        
        while(i >= 0)  {
            if (combination[i] <= n - k + i){
                combination[i] ++;
                
                for (int j = i + 1; j <= k - 1; j++){
                    combination[j] = combination[j - 1] + 1;
                }
                
                combinations.push_back(combination);
                
                i = k - 1;
            }
            else{
                i --;
            }
        }
        
        return combinations;
    }
};



