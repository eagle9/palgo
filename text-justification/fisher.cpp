/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Text Justification.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Text Justification.

fisherlei, look like clean node, not very if elses
http://fisherlei.blogspot.com/2013/01/leetcode-text-justification.html

*/
class Solution {
public:
    
    vector<string> fullJustify(vector<string> &words, int L) {   
           vector<string> result;   
            if(0 == words.size()) return result;     
            int i =0;   
            while(i< words.size())   
            {   
                int start = i;   
                 int sum = 0;   
                 while(i<words.size() && sum + words[i].size()<=L)   
                 {   
                      sum+=words[i].size() +1;   
                      i++;   
                 }   
                 int end = i-1;    
                 int intervalCount = end - start;   
                 int avgSp = 0, leftSp = 0;   
                 if(intervalCount >0)   
                 {   
                      avgSp = (L-sum + intervalCount+1)/intervalCount;   
                      leftSp = (L-sum + intervalCount+1)%intervalCount;   
                 }      
                 string line;      
                 for(int j = start; j<end; j++)   
                 {   
                      line+=words[j];   
                      if(i == words.size()) // the last line  
                      line.append(1, ' ');   
                      else   
                      {   
                           line.append(avgSp, ' '); //average space  
                           if(leftSp>0) // the extra space  
                           {   
                                line.append(1, ' ');   
                                leftSp--;   
                           }   
                      }   
                 }   
                 line+=words[end];   
                 if(line.size()<L)   
                      line.append(L-line.size(), ' ');   
                 result.push_back(line);      
            }   
            return result;   
       }   
};
