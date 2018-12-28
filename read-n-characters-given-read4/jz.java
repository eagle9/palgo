/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    //jz idea, shaun commented
    //beats 100%
    public int read(char[] buf, int n) {
        char[] buf4 = new char[4];
        int offset = 0;
        
        while (true) {
            //get size<=4 chars using read4
            int size = read4(buf4);
            
            //copy buf4 to buf, for each char copied, offset++
            //for (int i = 0; i < size && offset < n; i++) {
            for (int i = 0; i < size; i++) {
                buf[offset++] = buf4[i];
            }
            //read4 return 0 or offset reaches n
            //guaranteed conditions will be satisfied, so surely return
            //size == 0 implies that file ends 
            //offset == n implies all n chars read
            //if (size ==0 || offset == n) {
            if (size < 4 || offset == n) {
                return Math.min(offset,n);
                //return offset; //works too
            }
        }
    
    }
}
