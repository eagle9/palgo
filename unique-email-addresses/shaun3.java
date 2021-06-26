//Runtime: 35 ms, faster than 12.07% of Java online submissions for Unique Email Addresses. using substring(0,i)
//Memory Usage: 41.6 MB, less than 5.06% of Java online submissions for Unique Email Addresses.
//Runtime: 17 ms, faster than 59.43% of Java online submissions for Unique Email Addresses. using toCharArray
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String e: emails) {
            String [] a = e.split("@");
            if (a.length == 2) {
                //first +, anything after in name should be ignored
                
                
                StringBuilder name = new StringBuilder();
                for (char c: a[0].toCharArray()) {
                    if (c == '+') break;
                    if (c == '.') continue;
                    name.append(c);
                }
                set.add(name.toString() + "@" + a[1]);
            }
        }
        return set.size();
    }
}
