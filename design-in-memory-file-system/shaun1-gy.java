/*grandyang c++ idea, understood, shaun rewrite in java 

//cutting: read the problem statement carefully, key targets: file and directory
file full path ---- string content, so we use hashmap from full path string to string content, 
so we use unordered_map<string,string> to represent files

directory --- dir full path  ---> ordered file_name/directory name (unique), so naturally we use
unordered_map<string,unordered_set<string>> to represent dirs

once we has the data storage, it is easy to design the services (ls, mkdir, addContentToFile, readContentFromFile)

//runtime 76ms, faster than 93%, mem less than 100%

*/
class FileSystem {

    public FileSystem() {
        //dirs["/"];
        dirs = new HashMap<>();
        dirs.put("/", new TreeSet<>());
        files = new HashMap<>();
    }
    
    
    //according to problem statement: "If it is a directory path, return the list of file and directory names in this directory, in lexicographic order
    private HashMap<String, TreeSet<String>> dirs; //dir name to the ordered set of file/dir 
    
    //problem statement: Given a file path and file content in string format
    private HashMap<String, String> files; //file full path to its content
    
    public List<String> ls(String path) {
        List<String> res = new ArrayList<>();
        //path is a file
        if (files.containsKey(path)) {
            //int idx = path.find_last_of('/');
            int idx = path.lastIndexOf('/');
            //according to problem statement, return file name(no path)
            //return {path.substr(idx + 1)};
            res.add(path.substring(idx+1));
            return res;
        }
        //path is not a file, a directory instead
        //auto t = dirs[path];
        dirs.putIfAbsent(path, new TreeSet<>());
        Set<String> set = dirs.get(path);
        //convert set of string to vector of string
        //return vector<string>(t.begin(), t.end());
        for (String entry: set) {
            res.add(entry);
        }
        return res;
    }
    
    public void mkdir(String path) {
        
        String dir = "";
        //create all middle dirs if not exist
        //for example /a/b/c/file_name
        //grow the path token by token, join by /
        String [] tokens = path.split("/");
        for (String t: tokens) {
            if (t.isEmpty()) continue; //skip the empty before first /
            if (dir.isEmpty()) dir += "/";
            //dirs[dir].insert(t); // t is file/dir_name under dir
            dirs.putIfAbsent(dir, new TreeSet<>());
            dirs.get(dir).add(t);
            //if (dir.size() > 1) dir += "/";
            //dir += t;
            //dir += dir =="/"? t: "/" + t;
            dir += dir.equals("/")? t: "/"+t;
            
        }
    }
    
    public void addContentToFile(String filePath, String content) {
        //split filePath into path and file_name, last /
        int idx = filePath.lastIndexOf('/');
        String path = filePath.substring(0, idx);
        String file_name = filePath.substring(idx + 1);
        if (path.isEmpty()) path = "/";
        
        //if path is new, mkdir path
        if (!dirs.containsKey(path)) mkdir(path);
        
        //if file_name not in path yet, add otherwise no change dirs[path] is a set
        //dirs[path].insert(file_name);
        dirs.putIfAbsent(path, new TreeSet<>());
        dirs.get(path).add(file_name);
        
        //append content to filePath
        //files[filePath].append(content);
        files.putIfAbsent(filePath,"");
        files.put(filePath, files.get(filePath)+ content);
    }
    
    public String readContentFromFile(String filePath) {
        //return files[filePath];
        files.putIfAbsent(filePath, "");
        return files.get(filePath);
    }
    

};

