/*
让我们群组给定字符串集中所有的错位词，所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，比如abc，bac, cba等它们就互为错位词，那么我们如何判断两者是否是错位词呢，我们发现如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法，由于错位词重新排序后都会得到相同的字符串，我们以此作为key，将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结果res中即可
grandyang idea1, runtime 25ms, faster than 77%
*/
class Solution1 {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            char [] c = str.toCharArray();
            Arrays.sort(c);
            String key = new String(c);
            List<String> list = map.getOrDefault(key, new ArrayList<>());
            list.add(str);
            map.put(key,list);
            
        }
        for (String key : map.keySet()) {
            res.add(map.get(key));
        }
        return res;
    }
}
/*
用一个大小为26的int数组来统计每个单词中字符出现的次数，然后将int数组转为一个唯一的字符串，跟字符串数组进行映射，这样我们就不用给字符串排序
grandyang idea2, runtime 86ms, faster than 14%
*/
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> m = new HashMap<>();
        for (String str : strs) {
            int [] cnt = new int[26];
            String key = "";
            char [] chars = str.toCharArray();
            for (char c : chars) ++cnt[c - 'a'];
            for (int d : cnt) key += String.valueOf(d) + ",";
            List<String> list = m.get(key);
            if (list == null) list = new ArrayList<>();
            list.add(str);
            m.put(key,list);
        }
        for (String key : m.keySet()) {
            res.add(m.get(key));
        }
        return res;
    }
}
