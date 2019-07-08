/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
//https://www.jianshu.com/p/b77ae5d669b1
//runtime 0ms, faster than 100%, mem less than 67%
//cutting angle, use master.guess's feedback, which is the number of char matches.  use the number of matches to shink the wordlist. 
// after a master.guess, at least we know there are x chars right in our guess. so we require next wordlist must all have these chars. 
class Solution {
public:
    int match(const string a, const string b){
        int ans = 0;
        
        for(int i = 0;i<a.length(); i++){
            if(a[i] == b[i]) ++ans;
        }
        
        return ans;
    }
    
    void shrinkWordList(vector<string>& wordlist, const string guessword, const int matches){
        vector<string> tmp;
        
        for(string word : wordlist){
            int m = match(word, guessword);
            if(m == matches){
                tmp.push_back(word);
            }
        }
        
        wordlist = tmp;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        
        //string target = wordlist[random() % wordlist.size()];
        string target = wordlist[rand() % wordlist.size()];
        //int Count = 10;
        //while (--Count)
        //problem statement: you have 10 guesses with master.guess api 
        for (int count= 0; count < 10; ++count){
            //feedback
            int matches = master.guess(target);
            
            shrinkWordList(wordlist, target, matches);
            
            target = wordlist[rand() % wordlist.size()];
        }
        
    }
};


/*
解题思路：
题目乍一看，特别像小时候 非常6+1节目，主持人让观众查价格，也有反馈机制，会告诉距离目标价格高了 还是 低了。
给出的wordlist词表长度，一定会大于10。不然遍历枚举查询就可以了(┑(￣Д ￣)┍)
基于贪心策略，我们应该要利用好系统的反馈机制，避免我们浪费查询机会。我们的目标应该是提高每次的 matches 值，即每次都要淘汰词表里不等于matches的单词，缩小我们枚举范围。
每次查询之后，如果matches不等于6，我们虽然还不知道"secret"。但我们知道哪些一定不是"secret"，进而缩小范围，逼近答案

作者：778477
链接：https://www.jianshu.com/p/b77ae5d669b1
来源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
*/
