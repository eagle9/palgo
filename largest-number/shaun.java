//first try my own try,   Integer [] a is not a good starting point, not accepted
//inspired by leetcode solution, String [] a is good start
//key is coming up with customized Comparator<T>
//beats 99%
class Solution {
    
    public String largestNumber(int[] nums) {
        
        //Arrays.sort(nums, new Comparator<Integer,Integer>() {
        String [] a = new String[nums.length];
        for (int i =0; i < nums.length; i++) {
            a[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(a, new Comparator<String>() {
        //Collections.sort(a, new Comparator<String>() {
            public int compare(String a, String b) {
                String ab = a+b;
                String ba = b+a;
                return ab.compareTo(ba);
            }
        }); 
        
        //for case [0, 0], if max is 0, then return "0" rather than "00"
        if (a[a.length -1].equals("0"))
            return "0";
        
        String s = "";
        for (int i = a.length-1; i >= 0; i--)
            s += a[i];
        return s;
    }
    
}

