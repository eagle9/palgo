/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */
class GFSClient : public BaseGFSClient {
public:
    int chunkSize;
    map<string, int> chunkNum; //file name to number of chunks, chunk 0 to num-1 

    GFSClient(int chunkSize) {
        // initialize your data structure here
        this->chunkSize = chunkSize;
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string& filename) {
        // Write your code here
        // return "" instead of NULL if file do not exist
        if (chunkNum.find(filename) == chunkNum.end()) {
            return "";
        }
        string content = "";
        int size = chunkNum[filename];
        for (int i = 0; i < size; ++i) {
            content += readChunk(filename, i);
        }

        return content;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string& filename, string& content) {
        int length = content.size();
        int num = (length - 1) / chunkSize + 1; //number of chunks
        chunkNum[filename] = num;
        for (int i = 0; i < num; ++i) {
            string sub_content = content.substr(i * chunkSize, chunkSize);
            writeChunk(filename, i, sub_content);
        }
    }
};
