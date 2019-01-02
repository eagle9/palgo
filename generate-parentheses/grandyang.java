public class Solution {
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    public List<String> generateParenthesis(int n) {
        // write your code here
        List<String> res = new ArrayList<>();
        
        helper(n,n,"",res);
        return res;
    }
    
    
    //grandyang idea, beats 61%
    //run some tests? 
    //@left: number of ( to add)
    //@right: number of ) to add
    void helper(int left, int right, String cur, List<String> res) {
        if (left == 0 && right == 0) {
            res.add(cur);
            return;
        }
        if (left > right) //need add more ( than ), not valid 
            return;
            
        if (left > 0) {
            helper(left-1,right, cur + "(",res);
        }
        if (right >0) {
            helper(left,right-1, cur + ")",res);
        }
        
    }
    
    /* tests
    n = 2: (())  ()()
    yes i can test with a binary tree
             h(2,2)
             /   \
         h(1,2)   h(2,1)  XXXXX cause )... left > right return, no further
         /   \
       h(0,2)  h(1,1)
       \      /     \
        h(0,1)      h(1,0)  XXX cause ())...
          \
           h(0,0)  => (()), ()()    left, right = 0,0, record results
    once you draw the recursion tree, the coding part is super easy
    n = 3: ((()))  (())() ()(()) ()()()
    
    */
}
