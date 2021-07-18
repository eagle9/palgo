/*
不同之处在于那道题的计算符号只有加和减，而这题加上了乘除，那么就牵扯到了运算优先级的问题，好在这道题去掉了括号，还适当的降低了难度，估计再出一道的话就该加上括号了。不管那么多，这道题先按木有有括号来处理，由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了

*/
class Solution {
    public int calculate(String str) {
        char [] s = str.toCharArray();
        long res = 0, num = 0, n = s.length;
        char op = '+';
        Stack<Long> st = new Stack<>();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    long tmp = (op == '*') ? st.pop() * num : st.pop() / num;
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            } 
        }
        while (!st.empty()) {
            res += st.pop();
        }
        return (int)res;
    }
}
