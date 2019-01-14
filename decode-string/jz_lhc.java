/*
#jz linghuchong idea, 把所有字符一个个放到 stack 里， 如果碰到了 ]，就从 stack 找到对应的字符串和重复次数，decode 之后再放回 stack 里
#shaun java translate, 6ms, faster than 13%

*/
class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c: s.toCharArray()) {
            if (c != ']') {
                stack.push(c);
                continue;
            }
            //now c == ], pop stack till [
            StringBuilder sb = new StringBuilder();
            while (!stack.isEmpty() && stack.peek() != '[') {
                sb.append(stack.pop());
            }
            //now stack.peek() == [, skip it
            stack.pop();
            
            //now figure out the repeat number
            int base = 1, reps = 0;
            while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                reps += (stack.pop() - '0')*base;
                base *= 10;
            }
            
             
            for (int i = 0; i < reps; i++) {
                for (int j = sb.length()-1; j>=0; j--)
                    stack.push(sb.charAt(j));
            }
            
        }
        
        StringBuilder res = new StringBuilder();
        for (char c: stack) res.append(c);
        return res.toString();
    }
}

