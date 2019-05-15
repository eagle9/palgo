//http://fisherlei.blogspot.com/2017/07/leetcode-palindrome-pairs-solution.html
//fisherlei idea, clean evalutation of the problem and clean idea
//shaun has read and understand
//runtime 212ms, faster than 89%, mem less than 52%
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {  
        unordered_map<string, int> dict; //word's reverse to its index
        set<vector<int>> result;  //use set to prevent duplication
        for(int i =0; i< words.size(); i++) {  
            string word = words[i];  //copy it
            reverse(word.begin(), word.end()); //reverse it
            dict[word] = i;  
        }
        
        for(int i =0; i< words.size(); i++) {  
            string word = words[i];  
            // 切字符串三种情况，最左边切，中间切，和最右边切。   
            //注意，这里j<= word.size()为了cover最右边切这种情况  
            for(int j = 0; j<=word.size(); j++) {  
                string left = word.substr(0, j);  
                string right = word.substr(j, word.size() - j);  
                // candi | left | right  
                if(isPalindrome(left) && dict.find(right) != dict.end() && dict[right] != i) {  
                    result.insert({dict[right], i});
                    //result.emplace({dict[right], i});
                }  
                // left | right | candi  
                if(isPalindrome(right) && dict.find(left) != dict.end() && dict[left] != i) {  
                    result.insert({i, dict[left]});
                    //result.emplace({i, dict[left]});
                }  
            }   
        }  
        vector<vector<int>> output(result.begin(), result.end());   
        return output;  
    }  
    bool isPalindrome(string& str) {  
      int left = 0, right = str.size() -1;  
      while(left < right) {  
        if(str[left++] != str[right--]) return false;  
      }  
      return true;  
    }  

};
