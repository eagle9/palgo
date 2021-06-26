//grandyang string parsing compiler 
// cutting: block comment dealing is key, use bool blocked to track block comment open and close
//  key token to look for //, /*, and */, so we need to look at 2 char substring within a line

//blocked comment can be part of a line, or span multiple lines

// critical to list and comtemplate all the cases
//runtime 0ms, faster than 100%, mem less than 19%
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool blocked = false; //block comment can span over multiple lines, so we need this bool variable
        string out = "";
        for (string line : source) {
            for (int i = 0; i < line.size(); ++i) {
                if (!blocked) {//no block yet
                    //look at 2 chars a time
                    if (i == line.size() - 1) out += line[i];
                    else {
                        string t = line.substr(i, 2);
                        if (t == "/*") {
                            blocked = true; 
                            ++i;
                            //no break here, since */ come up later before end of line
                        }
                        else if (t == "//") break; //break out for this line
                        else out += line[i];
                    }
                } else { //block started, look for */
                    //look at 2 chars at a time, look for */
                    //otherwise continue loop
                    if (i < line.size() - 1) {
                        string t = line.substr(i, 2);
                        if (t == "*/") {
                            blocked = false;
                            ++i;
                        }
                    }
                }
            }
            //end of line now,  check example2 in problem statement, join block comment begin line and end line
            //in other words, if blocked, no output to res, instead, append stuff on next line
            if (!out.empty() && !blocked) {
                res.push_back(out);
                out = "";
            }
        }
        return res;
    }
};
