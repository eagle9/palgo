/*
https://blog.csdn.net/u012050154/article/details/51604942
walker xiaozhu idea using stack
cutting:  
   count each char's frequency in the given string
to make result string the smallest in lexicographical order, keep small char in front



以“bcabc”为例：
对于第一个字符b，因为b第一次出现，则保留下来，res="b";
对于第二个字符c，因为c第一次出现，而且比b大，则保留下来，res="bc"；
对于第三个字符a，因为a第一次出现，所以应该保留，但a比b和c都小，则分为两种情况：
如果在原字符串中，a后面还有b则应该把b移除，则把a放在c的后面,res="ca"；有c时同理，res="a";
如果在原字符串中，a后面没有b和c，则只能把a放在bc后面，res="bca"

use a stack to keep the chars, pop removable chars (greater, has more by count hash)
   pop the char, flag visited hash map to false
keep popping until all removal chars are popped, so use a while loop
all popped, push the char into stack, go check next char in the string, so there is a loop for each char in the string

runtime 3ms, faster than 74%, mem less than 100%
 ———————————————— 
版权声明：本文为CSDN博主「行者小朱」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u012050154/article/details/51604942

*/
class Solution {
    String removeDuplicateLetters(String str){
        if(str==null)
            return null;

        int[] count = new int[26];//统计每个字符出现次数, only lower case letters
        for(int i=0; i<str.length(); i++)
            count[str.charAt(i)-'a']++;		

        Stack<Character> stack = new Stack<>();
        boolean[] visited  = new boolean[26];//标记数组，标记每个字符是否被访问过。默认初始化为false
        for(int i=0; i<str.length(); i++){
            count[str.charAt(i)-'a']--;			

            if(visited[str.charAt(i)-'a'])
                continue;

            //pop char at the top of stack when it is > current char and there are more of its copies to follow in the string
            while(!stack.isEmpty() &&   stack.peek() > str.charAt(i) && count[stack.peek()-'a']>0){
                visited[stack.peek()-'a'] = false;
                stack.pop();
            }
            //now all removable chars > current char have been removed
            stack.push(str.charAt(i));
            visited[str.charAt(i)-'a'] = true;
        }

        StringBuilder res = new StringBuilder();
        for(char ch : stack)
            res.append(ch);

        return res.toString();
    }
    
}
