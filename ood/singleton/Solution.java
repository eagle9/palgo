//jz, beats 100%
class Solution {
    /**
     * @return: The same instance of this class every time
     */
    public static Solution instance = null;
    public static Solution getInstance() {
        if (instance == null) {
            instance = new Solution();
        }
        return instance;
    }
	public static void main(String [] args) {
		Solution a =  Solution.getInstance();
		Solution b = Solution.getInstance();
		if (a == b) System.out.println("Correct");
		else System.out.println("Wrong");
	}
};
