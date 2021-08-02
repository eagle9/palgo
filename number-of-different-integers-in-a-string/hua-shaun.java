class Solution {
    public int numDifferentIntegers(String word) {
        word += "$";
        char [] c = word.toCharArray();
        
        int i = 0;
        //digits could be huge number, use string to store it
        Set<String> set = new HashSet<>();
        //Deque<Character> cur = new ArrayDeque<>();
        Deque<Character> cur = new LinkedList<>();
        for  (; i < c.length; i++) {
            if (Character.isDigit(c[i])) {
                cur.addLast(c[i]);
            }
            //not digit
            else if (!cur.isEmpty()) {
                //deal with digits seen before
                //first trim leading 0, single 0 okay, more than that trim it
                while (cur.size() > 1 && cur.peekFirst() == '0')
                  cur.removeFirst();
                StringBuilder sb = new StringBuilder();
                while (!cur.isEmpty()) {
                    sb.append(cur.removeFirst());
                }
                set.add(sb.toString());
                cur.clear();
            }
            
        }
        
        return set.size();
    }
}

