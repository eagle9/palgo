//yuanbin, shaun modified, beats 95.60%
public class Solution {
    public String reverseWords(String s) {
        if (s == null || s.trim().isEmpty()) {
            return "";
        }

        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            if (!words[i].isEmpty()) {
                if (sb.length() > 0 )
                    sb.append(" ");
                sb.append(words[i]);
            }
        }
        return sb.toString();
        //return sb.substring(0, sb.length() - 1);
    }
}
