class Solution {
    //beats 98%
    public boolean rotateString1111(String A, String B) {
        if (A.length() != B.length())
            return false;
        String AA = A + A;
        return   AA.indexOf(B) >= 0? true: false;
    }
    
    //beats 99%, grandyang idea, shaun coded in java
    public boolean rotateString(String A, String B) {
        int n = A.length();
        
        if (n != B.length()) return false;
        if (n==0) return true;
        if (n ==1) return A.equals(B);
        
        //n >=2 now
        //split A to ab   ba == B??
        for (int i = 1; i <= n-1; i++) {
            String a1 = A.substring(0,i);
            String a2 = A.substring(i,n);
            if (B.equals(a2+a1)) return true;
            
            
        }
        return false;
    }
}
