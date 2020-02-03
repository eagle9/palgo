/*

column 1(from bottom) becomes row 1 

requirement: rotate in place, no extra storage
7 to 1
1 to 3
3 to 9

ij, row i col j
---> row j col n-i, save it first

how to in place? 
1 -> 3 -> 9 ->7->1

Time will be n^2, only diagonal and above
rotate elements 
how to track all ready rotated?
9 --- 2+1
16 --- 4

shaun first try, wrong answer, correct idea direction 
but rotating 4 elements index not getting correct. not going through all cases. just 1 case and done. 
no no. 

*/

class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        
        //for (int i = 0, start =0, end =n-2; i < n && start <= end; i++, start++) {
        //    for (int j = start; j <= end; j++) {
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n-1-i; j++) {
                int temp = matrix[i][j];  //00->temp
                matrix[i][j] = matrix[n-1-j][i];   //20 ---> 00 . 7->1
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; //9--->7
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; //3--->9
                matrix[j][n-1-i] = temp; //1-->3
            }
        }
    }
    
}

/*
ij  becomes  row j, col n-1-i ----- cutting 
had this idea at the beginning, then deviate from this with examples

how to limit the loops, i had to check with gy, sigh

i = 0, start = 0, end =3-2=1

20 --> 00    7-->1
22->   20    9-->7
02 --> 22 .  3->9
00 -> 02
 
01 -->temp    2->temp
 10 ->  01    4->2
 21 -> 10 .   8->4
 11 -> 21 .   6->8
 01 -> 11 .   2->6



*/
