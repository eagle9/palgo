/*

Runtime: 25 ms, faster than 75.33% of Java online submissions for Find Duplicate File in System.
Memory Usage: 49.7 MB, less than 100.00% of Java online submissions for Find Duplicate File in System.

shaun own idea with map<String,List<String>>
*/
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        List<List<String>> res = new ArrayList<>();
        Map<String,List<String>> map = new HashMap<>();
        for (String path: paths) {
            String [] a = path.split(" ");
            String dir = a[0];
            for (int i = 1; i < a.length; i++) {
                int iLeft = a[i].indexOf("("), iRight = a[i].indexOf(")");
                
                String fn = a[i].substring(0,iLeft);
                String content = a[i].substring(iLeft+1,iRight);
                List<String> list = map.getOrDefault(content, new ArrayList<>());
                list.add(dir + "/" + fn);
                if (!map.containsKey(content)) map.put(content, list);
            }
        }
        
        for (List<String> list: map.values()) {  //valueSet()
            if (list.size() >= 2) res.add(list);
        }
        return res;
    }
}



//grandyang idea, shaun fully understands and rewrite own style
//runtime 124, faster than 56%, mem less than 21%
//cutting, string parse tokenizer, hash table, understand problem asks

