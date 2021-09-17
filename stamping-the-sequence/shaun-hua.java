//hua 
class Solution {
    public int[] movesToStamp(String stamp, String target0) {
        char [] target = target0.toCharArray();
        List<Integer> ans = new LinkedList<>();
        boolean [] seen = new boolean[target.length];
        //total number of ? 
        int total = 0;
        while (total < target.length) {      
          boolean found = false;
            //try all possible indexes to unstamp
          for (int i = 0; i <= target.length - stamp.length(); ++i) {
            if (seen[i]) continue;
            int l = unStamp(stamp, target, i);
            if (l == 0) continue;//can not be unstamped
            seen[i] = true;
            total += l;
            ans.add(i);
            found = true;
          }
          if (!found) return new int[0];
        }
        Collections.reverse(ans);
        int[] a = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++) a[i] = ans.get(i);
        return a;
    }
    
    //return number of chars that has been unstamped
    private int unStamp(String stamp, char[] target, int s) {    
        int l = stamp.length();
        for (int i = 0; i < stamp.length(); ++i) {
          if (target[s + i] == '?') --l;
          else if (target[s + i] != stamp.charAt(i)) return 0; //early return when no match
        }

        //all match from start = s, stamp all to ?
        if (l != 0) {
            for (int i = 0; i < stamp.length(); i++) {
                target[s + i] = '?';
            }
        }
        return l;
    }
}
