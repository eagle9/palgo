// Forward declaration of the read4 API.
int read4(char *buf);

//jz idea and shaun code
//runtime 4ms, faster than 74%, mem less than 63%
class Solution1 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        //char[] buf4 = new char[4]; java array declaration and allocation
        char buf4[4] ; //c array declaration and allocation
        int ib = 0; //index for big buffer buf 
        
        while (true) {
            //get size<=4 chars using read4
            int size = read4(buf4);
            
            //copy buf4 to buf, for each char copied, offset++
            //for (int i = 0; i < size && offset < n; i++) {
            for (int i = 0; i < size; i++) {
                buf[ib++] = buf4[i];
            }
            //read4 return 0 or offset reaches n
            //guaranteed conditions will be satisfied, so surely return
            //size == 0 implies that file ends 
            //offset == n implies all n chars read
            //if (size ==0 || offset == n) {
            //either read4 reaches end, size < 4
            //or n chars have been read
            if (size < 4 || ib >= n) {
                return min(ib,n);
                //return offset; //works too
            }
        }
    }
};


//jiadai idea, shaun modified, beats 100%
//directly use char *buf
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        for (;;) {
            //read cur chars and store them at buf+res
            int size = read4(buf);

            count += size;
            buf += size;
            if (size < 4) break;//works too
            //if (size == 0) break;
            if (count >= n) break;
        }
        return min(count,n);
        //return offset;
    }
};

