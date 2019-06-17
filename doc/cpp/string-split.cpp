//shaun with split and stack
//runtime 8ms, faster than 88.70%, mem less than 9%
#include <sstream>
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        //vector<string> tokens = split(path,'/');
        vector<string> tokens = split(path,"/");
        for (string token: tokens) {
            //case 1 and 2
            if (token == "." || token == "") continue;
            //case 3 token == ..
            if (token == "..") { 
                if (!st.empty()) st.pop();
                continue;
            }
            
            //case 4 valid folder name
            st.push(token);
        }
        
        if (st.empty()) return "/"; //bug 1 .. return ""
        string ans;
        while (!st.empty()) {
            string folder_name = st.top(); st.pop();
            ans = "/" + folder_name + ans;
        }
        return ans;
    }
private:
    //use stringstream getline to tokenize string with char delim, limited to char delim
    vector<string> split (const string &s, char delim) {
        vector<string> result;
        stringstream ss (s);
        
        string token;
        while (getline (ss, token, delim)) { //getline delim only supports char type
            result.push_back (token);
        }

        return result;
    }
    
    //use string::find_first_of(delim, start) to implement java style string split
    //runtime 8ms, faster than 88.40%, mem less than 9%
    vector<string> split(string& s, string delim)  { 
    //vector<string> split(string& s, string& delim)  {  //bug if you call with literal delim, reference not working 
        size_t prev = 0; //prev index of delim
        size_t index=s.find_first_of(delim,prev); //current index of delim
        vector<string> res;
        while (index!=string::npos)  {  
            res.push_back(s.substr(prev,index-prev));  
            prev=index+1; //  
            index=s.find_first_of(delim,prev);  
        }  
        if (index-prev>0)  {  
            res.push_back(s.substr(prev,index-prev));  
        }  
        return res;
    }
};

