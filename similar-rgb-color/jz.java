class Solution {
    //jz grandyang idea, beats only 3%, not quite understand
    public String similarRGB(String color) {
        return "#" + helper(color.substring(1,3)) + helper(color.substring(3,5)) + helper(color.substring(5,7));
    }
    private String helper(String str){
        //String dict = "0123456789abcdef";
        int num = Integer.parseInt(str, 16);
        int idx = num/17 + (num % 17 > 8 ? 1 : 0);
        return String.format("%02x", idx * 17);
    }
}


