/*
更加巧妙的利用偏移字符串的特点，那就是字符串的每个字母和首字符的相对距离都是相等的，比如abc和efg互为偏移，对于abc来说，b和a的距离是1，c和a的距离是2，对于efg来说，f和e的距离是1，g和e的距离是2。再来看一个例子，az和yx，z和a的距离是25，x和y的距离也是25(直接相减是-1，这就是要加26然后取余的原因)，那么这样的话，所有互为偏移的字符串都有个unique的距离差，我们根据这个来建立映射就可以很好的进行单词分组了，这个思路真实太赞
great idea, shaun java code, runtime 8ms, faster than 29%
*/
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        //Arrays.sort(strings);   //sort at beginning, 10ms
        List<List<String> > res = new ArrayList<>();
        Map<String, List<String>> m = new HashMap<>();
        for (String s : strings) {
            String pattern = "";
            char [] c = s.toCharArray();
            for (int i = 0; i < c.length; i++) {
                pattern += ((c[i] + 26 - c[0]) % 26) + ",";
            }
            List<String> list = m.getOrDefault(pattern,new ArrayList<>());
            list.add(s);
            m.put(pattern,list);
        }
        for (String k: m.keySet()) {
            List<String> list = m.get(k);
            Collections.sort(list); //runtime 8ms
            res.add(list);
            
        }
        return res;
    }
}
