//runtime 16ms, faster than 76%, mem less than 42%
//massivealgo idea, direct thinking from problem statment, just have to get details right
//using a for loop
class Solution1 {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty()) return false;
       
        for (int i  = 0; i < data.size(); ++i) {
            if (data[i] > 255) return false;
            int numberOfBytes = 0;
            if((data[i] & 128) == 0) { // 0xxxxxxx, 1 byte, 128(10000000), high bit 0
                numberOfBytes = 1;
            } else if((data[i] & 224) == 192) { // 110xxxxx, 2 bytes, 224(11100000), 192(11000000)
                numberOfBytes = 2;
            } else if((data[i] & 240) == 224) { // 1110xxxx, 3 bytes, 240(11110000), 224(11100000)
                numberOfBytes = 3;
            } else if((data[i] & 248) == 240) { // 11110xxx, 4 bytes, 248(11111000), 240(11110000)
                numberOfBytes = 4;
            } else {
                return false;
            }
            //numberOfBytes byte including i
            for(int j=1;j<=numberOfBytes-1;j++) { // check that the next n bytes start with 10xxxxxx
                if(i+j>=data.size()) return false;
                if((data[i+j] & 192) != 128) return false; // 192(11000000), 128(10000000)
            }
            //i         i+n-1
            //1    .... numberOfBytes   
            i=i+numberOfBytes-1;
        }
        return true;
    }

};

//using a while loop
//runtime 16ms, faster than 76%, mem less than 45%
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty()) return false; //comment out works too
       
        for (int i = 0; i < data.size();) {
            if (data[i] > 255) return false;
            int numberOfBytes = 0;
            if((data[i] & 128) == 0) { // 0xxxxxxx, 1 byte, 128(10000000), high bit 0
                numberOfBytes = 1;
            } else if((data[i] & 224) == 192) { // 110xxxxx, 2 bytes, 224(11100000), 192(11000000)
                numberOfBytes = 2;
            } else if((data[i] & 240) == 224) { // 1110xxxx, 3 bytes, 240(11110000), 224(11100000)
                numberOfBytes = 3;
            } else if((data[i] & 248) == 240) { // 11110xxx, 4 bytes, 248(11111000), 240(11110000)
                numberOfBytes = 4;
            } else {
                return false;
            }
            //numberOfBytes byte including i
            for(int j=1;j<=numberOfBytes-1;j++) { // check that the next n bytes start with 10xxxxxx
                if(i+j>=data.size()) return false;
                if((data[i+j] & 192) != 128) return false; // 192(11000000), 128(10000000)
            }
            //i         i+n-1
            //1    .... numberOfBytes   
            i=i+numberOfBytes-1;
            i++;
        }
        return true;
    }

};

