//Runtime: 35 ms, faster than 12.07% of Java online submissions for Unique Email Addresses.
//Memory Usage: 41.6 MB, less than 5.06% of Java online submissions for Unique Email Addresses.
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String e: emails) {
            String [] a = e.split("@");
            if (a.length == 2) {
                //first +, anything after in name should be ignored
                String name = a[0];
                int i = name.indexOf("+");
                if (i >=0) {
                    name = name.substring(0,i);
                }
                name = name.replaceAll("\\.","");
                set.add(name + "@" + a[1]);
            }
        }
        return set.size();
    }
}
