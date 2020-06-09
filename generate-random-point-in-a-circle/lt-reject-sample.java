/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 
 
 Runtime: 9 ms, faster than 19.62% of Java online submissions for Implement Rand10() Using Rand7().
Memory Usage: 47.4 MB, less than 7.69% of Java online submissions for Implement Rand10() Using Rand7().
 */
class Solution extends SolBase {
    public int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
}
