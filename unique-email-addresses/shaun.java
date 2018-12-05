class Solution {
    
    //shaun's own code with some lookup of String api
    //accepted after fixing one typo, beats 57%
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String e: emails) {
            String [] a = e.split("@");
            //check a.length()
            if (a.length != 2) {  //invalid email
                continue;
            }
            String name = a[0];
            String host = a[1];
            
            //name from 0 to first +
            int i = name.indexOf("+");
            if (i > 0) {
                name = name.substring(0,i);
            } 
             
            //dot will be ignored in name
            //name = name.replaceAll(".","");
            name = name.replace(".",""); //works too
            //name = name.replace('.',''); //does not work
            //ask about upper and lower case
            
            set.add(name + "@" + host);
            
            
        }
        return set.size();
    }
}
