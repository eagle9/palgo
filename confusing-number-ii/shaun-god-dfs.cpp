//https://blog.csdn.net/Csdn_jey/article/details/92252222
//net god idea, understood, cutting, get next confusing number from 
//runtime 84ms, faster than 70%, mem less than 33%
class Solution {
public:
  int confusingNumberII(int N) {
    n = N;
    ans = 0;
    //keep construct number with 0 1 6 8 9 digits
    //0 1 6 8 9
    //10 11 16 18 19
    //60 61 66 68 69 
      //-->>> *10 *10+1, *10+6, *10+8, *10+9
    search(0);
    return ans;
  }
private:
  int n, ans;
  //recur search confusing number >= num
  void search(long num) {
    if (num > n) return;
    if (num) {
      if (rotate(num) != num) ++ ans;
    }
    if (num) search(num * 10);
    search(num * 10 + 1);
    search(num * 10 + 6);
    search(num * 10 + 8);
    search(num * 10 + 9);
  }
  long rotate(long x) {
    long y = 0;
    //get each digit of number x
    for (; x > 0; x /= 10) {
      int k = x % 10;
      switch (k) {
        case 6: k = 9; break;
        case 9: k = 6; break;
      }
      y = y * 10 + k;
    }
    return y;
  }
};

