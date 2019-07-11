//grandyang idea, shaun fully understands and rewrite own style
//runtime 124, faster than 56%, mem less than 21%
//cutting, string parse tokenizer, hash table, understand problem asks
class Solution1 {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        //group full file names by their conent string
        unordered_map<string, vector<string>> m;
        for (string path : paths) {
            //path = "root/a 1.txt(abcd) 2.txt(efgh)"
            //first token is dir, remaining token for each file under that dir
            istringstream is(path);
            string dir = "", token = "";
            is >> dir;
            while (is >> token) {
                int ip = token.find_last_of('(');
                string fname = dir + "/" + token.substr(0, ip); //last index = ip-1, len = ip-1-0+1 = ip
                //content from ip+1 to end-2, end-1 is )
                //  len  = token.size()-2 - ip - 1 + 1 = token.size()-ip -2
                string content = token.substr(ip + 1, token.size() - ip - 2);
                m[content].push_back(fname);
            }
        }
        for (auto kvpair : m) {
            //duplicate means >=2
            if (kvpair.second.size() >=2)res.push_back(kvpair.second);
        }
        return res;

    }
};

//shaun try with getline tokenizer
//runtime 124ms, faster than 56%, mem  less than 45%
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        //group full file names by their conent string
        unordered_map<string, vector<string>> m;
        for (string path : paths) {
            //path = "root/a 1.txt(abcd) 2.txt(efgh)"
            //first token is dir, remaining token for each file under that dir
            istringstream is(path);
            string dir = "", token = "";
            getline(is, dir, ' ');
            while (getline(is,token, ' ')) {
                int ip = token.find_last_of('(');
                string fname = dir + "/" + token.substr(0, ip); //last index = ip-1, len = ip-1-0+1 = ip
                //content from ip+1 to end-2, end-1 is )
                //  len  = token.size()-2 - ip - 1 + 1 = token.size()-ip -2
                string content = token.substr(ip + 1, token.size() - ip - 2);
                m[content].push_back(fname);
            }
        }
        for (auto kvpair : m) {
            //duplicate means >=2
            if (kvpair.second.size() >=2)res.push_back(kvpair.second);
        }
        return res;

    }
};
