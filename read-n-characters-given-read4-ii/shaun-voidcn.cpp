// Forward declaration of the read4 API.
int read4(char *buf);

//http://www.voidcn.com/article/p-tzmmcsae-zo.html
//runtime 0ms, faster than 100%, mem less than 6%
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(n == 0)
            return 0;
            
        int total = 0;
        //while(this->buffer.size() < n && !this->endOfFile) {
        while(buffer.size() < n && !endOfFile) {
            char* temp = new char[4];
            int r = read4(temp);
            if(r < 4)
                this->endOfFile = true;
            for(int i = 0; i < r; i++)
                this->buffer.push(temp[i]);
        }

        int l = min((int)this->buffer.size(), n);
        for(int i = 0; i < l; i++) {
            buf[i] = this->buffer.front();
            this->buffer.pop();
            total++;
        }
        return total;
    }
    
private:
    queue<char> buffer;
    bool endOfFile = false;
};
