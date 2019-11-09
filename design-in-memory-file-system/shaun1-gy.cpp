/*grandyang c++, understood
//cutting: read the problem statement carefully, key targets: file and directory
file full path ---- string content, so we use hashmap from full path string to string content, 
so we use unordered_map<string,string> to represent files

directory --- dir full path  ---> ordered file_name/directory name (unique), so naturally we use
unordered_map<string,unordered_set<string>> to represent dirs

once we has the data storage, it is easy to design the services (ls, mkdir, addContentToFile, readContentFromFile)

//runtime 20ms, faster than 80%, mem less than 100%

*/
class FileSystem {
public:
    FileSystem() {
        dirs["/"];
    }
    
    vector<string> ls(string path) {
        //path is a file
        if (files.count(path)) {
            int idx = path.find_last_of('/');
            //according to problem statement, return file name(no path)
            return {path.substr(idx + 1)};
        }
        //path is not a file, a directory instead
        auto t = dirs[path];
        //convert set of string to vector of string
        return vector<string>(t.begin(), t.end());
    }
    
    void mkdir(string path) {
        istringstream is(path);
        string t = "", dir = "";
        //create all middle dirs if not exist
        //for example /a/b/c/file_name
        //grow the path token by token, join by /
        while (getline(is, t, '/')) {
            if (t.empty()) continue; //skip the empty before first /
            if (dir.empty()) dir += "/";
            dirs[dir].insert(t); // t is file/dir_name under dir
            
            //if (dir.size() > 1) dir += "/";
            //dir += t;
            dir += dir == "/"? t: "/" + t;
            
        }
    }
    
    void addContentToFile(string filePath, string content) {
        //split filePath into path and file_name, last /
        int idx = filePath.find_last_of('/');
        string path = filePath.substr(0, idx);
        string file_name = filePath.substr(idx + 1);
        if (path.empty()) path = "/";
        
        //if path is new, mkdir path
        if (!dirs.count(path)) mkdir(path);
        
        //if file_name not in path yet, add otherwise no change dirs[path] is a set
        dirs[path].insert(file_name);
        
        //append content to filePath
        files[filePath].append(content);
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
    
private:
    //according to problem statement: "If it is a directory path, return the list of file and directory names in this directory, in lexicographic order
    unordered_map<string, set<string>> dirs; //dir name to the ordered set of file/dir 
    
    //problem statement: Given a file path and file content in string format
    unordered_map<string, string> files; //file full path to its content
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
