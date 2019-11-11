/*

//https://blog.csdn.net/cmy203/article/details/101225178

runtime 16ms, faster than 67%, mem less than 100%
解题思路：

一对花括号便是完整的表达式 ，重点在于如何处理逗号之间表达式的并集和非逗号间隔表达式的连接集。

从题意中可以了解到只要有逗号出现，逗号之前的表达式便与之后的表达式不存在连接的关系了，可以直接将逗号之前组成的字符串的集合加到结果中，但是如果是非逗号间隔的表达式就需要知道之前的表达式组成了什么样的字符串，也就是需要一个前缀，所以定义一个前缀所有字符串的集合unordered_set<string> prefixes,但遇到逗号时，将prefixes加入到res中，并清空prefixes ;

*/

class Solution {
public:
    vector<string> braceExpansionII(string expression) 
    {
        int pos = 0 ;
        unordered_set<string> strs = brace(expression , pos) ;
        vector<string> res(strs.begin() , strs.end()) ;
        sort(res.begin() , res.end()) ;
        return res ;
    }
    
    unordered_set<string> brace(string &expression , int &pos)
    {
        unordered_set<string> res , prefixes ;
        int len = expression.size() ;
        
        while(pos < len)
        {
            if(expression[pos] == '{')
            {
                pos++ ;
                unordered_set<string> words = brace(expression , pos) ;
                if(!prefixes.empty())
                {
                    str_multi(prefixes , words) ;
                }
                else
                    prefixes = words ;
            }
            else if(expression[pos] == ',')
            {
                str_add(res , prefixes) ;
                prefixes.clear() ;
                pos++ ;
            }
            else if(expression[pos] >='a' && expression[pos] <= 'z')
            {
                string s = "" ;
                while(expression[pos] >='a' && expression[pos] <= 'z')
                {
                    s += expression[pos] ;
                    pos++ ;
                }
                
                if(!prefixes.empty())
                {
                    unordered_set<string> new_prefixes ;
                    for(auto str : prefixes)
                        new_prefixes.insert(str + s) ;
                    
                    prefixes = new_prefixes ;
                }
                else
                    prefixes.insert(s) ;
            }
            else 
            {
                pos++ ;
                break ;    
            }
        }
        
        str_add(res , prefixes) ;
        
        return res ;
    }
    
    void str_multi(unordered_set<string> &prefixes , unordered_set<string> &words)
    {
        unordered_set<string> res ;
        
        if(words.empty()) return ;
        
        for(auto prefix : prefixes)
        {
            for(auto word : words)
                res.insert(prefix + word) ;
        }
        
        prefixes = res ;
    }
    
    void str_add(unordered_set<string> &res , unordered_set<string> &prefixes)
    {
        for(auto prefix : prefixes)
            res.insert(prefix) ;
    }
};

