//shaun's own code with some lookup of String api in java
// july 2019, write in c++
//c++ string manipulation is very different from java and python
//runtime 32ms, faster than 86%, mem less than 21%
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> set1;
        for (string e: emails) {
            int ia = e.find('@');
            if (ia == string::npos) continue; //skip invalid email
            string name = e.substr(0,ia), host = e.substr(ia+1);
            
            int ip = name.find('+');
            if (ip != string::npos) { // cut + and its following from name
                name = name.substr(0,ip);
            }
            //replace(name.begin(), name.end(), '.', ''); //not working
            //replace(name.begin(), name.end(), '.', '\0'); //not working either
            //name.erase('.'); //not working 
            
            for (auto it = name.begin(); it != name.end(); ++it) {
                if (*it == '.') name.erase(it);
            } //works
            //name.erase(std::remove(name.begin(), name.end(), 'a'), name.end()); //not working
            set1.insert(name + "@" + host);
            
        }
        return (int)set1.size();
    }
};

