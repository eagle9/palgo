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

runtime 0ms, faster than 100%, mem less than 67%
 ———————————————— 
版权声明：本文为CSDN博主「行者小朱」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u012050154/article/details/51604942

*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        //vector<int> count(26); //count of each char in the string, only lowerase letter, so size 26
        bool used[26] = {false}; //if a char is used in the result or not
        for (char ch: s) count[ch - 'a']++;
        
        //store the result in a vector, used as a stack
        //vector<char> st;
        //or use string directly as a stack, wow! c++ is so nice
        string st;
        
        for (char ch: s) {
            
            count[ch - 'a']--; //update remain count of this char moving from left to right in the string s
            if (used[ch - 'a']) continue;
            //remove all removable chars from top of stack: 
            // st.back()> ch and has more count[st.back()] > 0
            while (!st.empty() && st.back() > ch && count[st.back() - 'a'] > 0) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            //now all removable chars popped
            used[ch - 'a'] = true;
            st.push_back(ch);
            
        }
        return st;
        /*
        string res = "";
        for (char ch: st) res.push_back(ch);
        return res;*/
    }
};


