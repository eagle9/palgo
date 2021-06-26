//naive with 2 pointers
//cutting: for each i, find its the highest edge from 0 to i-1, and highest edge from i+1 to len - 1, then at it the water storage is min(leftHeight, rightHeight)- height[i]
//runtime 4ms, faster than 97%, mem less than 45%
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        vector<int> maxLeft(len); // 建一个array来存放maxLeft
        int max1=0;
        for(int i=0; i<len; i++){
            maxLeft[i]=max1; // max from 0 to i-1
            max1=max(max1, height[i]); 
        }
        
        vector<int> maxRight(len); // 同理，再建一个array来村反maxRight
        max1=0;
        for(int i=len-1; i>=0; i--){
            maxRight[i]=max1; //max from len-1 to i+1
            max1=max(max1, height[i]);
        }
 
        int water=0;      
        for(int i=0; i<len; i++){
            int diff=min(maxLeft[i], maxRight[i])-height[i];
            if(diff>0) water+=diff;
        }
        
        return water;
    }
};


