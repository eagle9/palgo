// Forward declaration of the read4 API.
int read4(char *buf);

//jiadai idea, shaun modified, beats 100%
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int offset = 0;
        for (;;) {
            //read cur chars and store them at buf+res
            int size = read4(buf);
            
            offset += size;
            buf += size;
            //if (size < 4) break;
            if (size == 0) break;
            if (offset == n) break;
        }
        return min(offset,n);
        //return offset;
    }
};
