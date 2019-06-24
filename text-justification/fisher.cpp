//fisherlei string manipulation, not much algo, but focus on implementation
//http://fisherlei.blogspot.com/2013/01/leetcode-text-justification.html
//runtime 0ms, faster than 100%, mem less than 71%
class Solution {
public:
    
    vector<string> fullJustify(vector<string> &words, int L) {   
           vector<string> result;   
            if(0 == words.size()) return result;
        
            int i =0;   
            while(i< words.size())   {   
                int start = i;   
                int sum = 0; //sum of chars to fill a line
                //consider adding words to a line
                while(i<words.size() && sum + words[i].size()<=L) {   
                      sum+=words[i].size() +1; //word and 1 space   
                      i++;  
                }
                
                int end = i-1;
                //fill word[start] .. words[end] to a line
                int sepCount = end - start; //separator count   
                int avgSp = 0, leftSp = 0;   
                if(sepCount >0) {   
                    avgSp = (L-sum + sepCount+1)/sepCount;   
                    leftSp = (L-sum + sepCount+1)%sepCount;   
                }
                //assemble a line with words and spaces
                string line;   
                for(int j = start; j<end; j++) {   
                    line+=words[j]; 
                    if(i == words.size()) // the last line  
                        line.append(1, ' ');   
                    else{   
                        line.append(avgSp, ' '); //average space  
                        if(leftSp>0) {// the extra space  
                              
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
